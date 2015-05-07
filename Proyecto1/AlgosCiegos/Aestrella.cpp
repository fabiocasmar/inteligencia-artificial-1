#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "nodo.hpp"
using namespace std;

struct orden{
    bool operator()(nodo *a, nodo *b){
        return a->costo > b->costo;
    }
};

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class NuestraPila : public std::priority_queue<T, Container, Compare>
{
public:
    typedef typename
        std::priority_queue<
        T,
        Container,
        Compare>::container_type::const_iterator const_iterator;

    const_iterator find(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (compare_states(*first->puntero,val)==0) return *first;
            ++first;
        }
        return NULL;
    }
};

nodo* Aestrella(state_t state, int (*funcion_g)(*state_t)){
	NuestraPila <nodo*,vector<nodo*>, orden> q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa_costo = new_state_map();
	nodo* nodoRaiz = new nodo(state,NULL,1);
	q.push(nodoRaiz);
	state_map_add(mapa_costo, &state, 0);

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.top();
		q.pop();

		if (is_goal(&aux->puntero)){
			cout << "Llegamos al goal! \n";
			return aux;
		}

		init_fwd_iter( &iter, &aux->puntero);
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ){
	    	const int costo = state_map_get(mapa_costo, &aux->puntero)+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	    	const int viejo_costo = state_map_get(mapa_costo, &hijo); 
	    	nodo *nodoAux = new nodo(hijo,aux,costo);
	    	nodo *nodoBusq  = q.find(nodoAux);
	    	if((nodoBusq==NULL)&&(state_map_get(mapa_costo, &hijo)!=NULL))continue;
            if ((viejo_costo > costo)||(nodoBusq==NULL)){
            	const int estimado = costo+funcion_g(&hijo);
            	state_map_add(mapa_costo, &hijo, costo);
				if(nodoBusq==NULL){
					q.push(nodoAux);
				}else{
					nodoAux->padre=aux;
					nodoAux->costo=estimado;
				}
			}
	    }
	}
	cout << "No hay camino hasta el goal \n";
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

    nodo* salida = Aestrella(raiz);
    imprimirCamino(salida);
}