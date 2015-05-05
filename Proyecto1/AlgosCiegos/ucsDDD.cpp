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

nodo* ucsDDD(state_t state){
	priority_queue<nodo*,vector<nodo*>, orden> q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa = new_state_map();
	nodo* nodoRaiz = new nodo(state,NULL,1);
	q.push(nodoRaiz);

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.top();
		q.pop();

		if (is_goal(&aux->puntero)){
			cout << "Llegamos al goal! \n";
			return aux;
		}

		init_fwd_iter( &iter, &aux->puntero);
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	    	const int costo = aux->costo+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	    	const int *viejo_costo = state_map_get(mapa, &hijo);
            if (viejo_costo == NULL || *viejo_costo > costo ) {
            	nodo *nodoAux = new nodo(hijo,aux,costo);
				state_map_add(mapa, &hijo, costo);
				q.push(nodoAux);
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

    nodo* salida = ucsDDD(raiz);
    imprimirCamino(salida);
}