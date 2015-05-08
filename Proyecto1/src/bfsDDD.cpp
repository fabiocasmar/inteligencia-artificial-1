#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include "nodo.hpp"

using namespace std;

nodo* bfsDDD(state_t state){
	queue<nodo*> q;
	int ruleid ;
    ruleid_iterator_t iter; 
    state_map_t *mapa = new_state_map();
    nodo* nodoRaiz = new nodo(state,NULL,1);
	q.push(nodoRaiz);

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.front();
		q.pop();

		if (is_goal(&aux->puntero)){
			cout << "Llegamos al goal! \n";
			return aux;
		}
		init_fwd_iter( &iter, &aux->puntero );
	    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	        apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	       	const int *visitado = state_map_get(mapa, &hijo );
	       	if (visitado == NULL){
	       		nodo *nodoAux = new nodo(hijo,aux,1);
	       		state_map_add(mapa, &hijo, 1);
	       		q.push(nodoAux);
	       	}
	    }
	    state_map_add(mapa,&aux->puntero,2);
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

    nodo* salida = bfsDDD(raiz);
    imprimirCamino(salida);
}