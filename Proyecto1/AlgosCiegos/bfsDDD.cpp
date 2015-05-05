#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <tr1/unordered_map>

using namespace std;

class nodo{
	public :
	state_t puntero;
	nodo* padre; 
	int costo;

	nodo(state_t x,nodo* y,int c){
	    puntero = x;
		if (y == NULL){
			padre = NULL;
		}
		else {
			padre = y;
		}
		costo = c;
	}

};

state_t bfsDDD(state_t state){
	queue<state_t> q;
	int ruleid ;
    ruleid_iterator_t iter; 
    state_map_t *mapa = new_state_map();
	q.push(state);

	while (!(q.empty())) {
	    state_t hijo;
		state_t aux = q.front();
		q.pop();

		if (is_goal(&aux.puntero)){
			cout << "Llegamos al goal! \n";
			return aux;
		}

		init_fwd_iter( &iter, &aux );
	    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	        apply_fwd_rule(ruleid, &aux.puntero, &hijo);
	       	const int *visitado = state_map_get(mapa, &hijo );
	       	if (visitado == NULL){
	       		state_map_add(mapa, &hijo, 1);
	       		q.push(hijo);
	       	}
	    }
	    state_map_add(mapa,&aux,2);
	}

	cout << "No hay camino hasta el goal \n";
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

    state_t salida = bfsDDD(raiz);
}