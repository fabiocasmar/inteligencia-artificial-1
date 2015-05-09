#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "./extras/nodo.hpp"
#include "./heuristicas/manhattan.cpp"
using namespace std;

struct orden{
    bool operator()(nodo *a, nodo *b){
        return a->costo > b->costo;
    }
};

 class NuestraPila : public priority_queue<nodo*,vector<nodo*>, orden>
{
public:
    typedef typename
    priority_queue<nodo*,vector<nodo*>,
    				orden>::container_type::const_iterator const_iterator;
    nodo *find(state_t val)
    {
        auto first = this->c.begin();
        auto last = this->c.end();
        nodo temp;
        while (first!=last) {
        	temp = **first;
            if (compare_states(&temp.puntero,&val)==0) return *first;
            ++first;
        }
        return NULL;
    }
};

nodo* aestrella(state_t state, int (*funcion_g)(state_t,int)){
	NuestraPila q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa_costo = new_state_map();
	state_map_t *mapa_estado = new_state_map();
	nodo* nodoRaiz = (nodo*)malloc(sizeof(nodo));
	nodoRaiz = new nodo(state,NULL,1);
	q.push(nodoRaiz);
	state_map_add(mapa_costo, &state, 1);
	state_map_add(mapa_estado, &state, 1);

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.top();
		q.pop();
		state_map_add(mapa_estado, &state, 2);

		if (is_goal(&aux->puntero)){
			cout << "Llegamos al goal! \n";
			return aux;
		}

		init_fwd_iter( &iter, &aux->puntero);
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ){
	    	int costo = *(state_map_get(mapa_costo, &aux->puntero))
	    											+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	    	int viejo_costo = *(state_map_get(mapa_costo, &hijo)); 
	    	nodo *nodoAux = new nodo(hijo,aux,costo);
	    	int temp = *state_map_get(mapa_estado, &hijo);
	    	if(temp==2)continue;
            if ((viejo_costo > costo)||(temp!=1)){
            	int estimado = costo+funcion_g(hijo,0);
            	state_map_add(mapa_costo, &hijo, costo);
				if(temp==0){
					state_map_add(mapa_estado, &hijo, 1);
					q.push(nodoAux);
				}else{
					nodoAux = q.find(hijo);
					nodoAux->padre=aux;
					nodoAux->costo=estimado;
				}
			}
	    }
	}
	cout << "No hay camino hasta el goal \n";
	return NULL;
}

void imprimirCamino(nodo* n){
	if (n == NULL){
		return;
	}
	cout << print_state(stdout,&n->puntero) << endl;
	imprimirCamino(n->padre);
}

int main(){
	char estadoIni[999];
    ssize_t nchars;
    state_t raiz;

	cout << "Introduzca un estado y presione ENTER : " << endl;
	cin.getline(estadoIni,999,'\n');
	
	nchars = read_state(estadoIni,&raiz);
    if (nchars <= 0) {
		cout << "Error: El estado introducido es invalido " << endl;
		return 0; 
    }

    
    nodo* salida = aestrella(raiz,calcularManhattan);
    imprimirCamino(salida);
}