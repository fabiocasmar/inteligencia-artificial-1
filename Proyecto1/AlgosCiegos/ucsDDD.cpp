#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "nodo.hpp"
using namespace std;

struct orden{
    bool operator()(nodo a, nodo b){
        return a.get_costo() > b.get_costo();
    }
};

void ucsDDD(state_t state){
	priority_queue<nodo,vector<nodo >, orden> q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa = new_state_map();

	q.push(*(new nodo(state,state,0)));

	while (!(q.empty())) {
	    state_t hijo;
		nodo aux;
		aux = q.top();
		q.pop();

		if (is_goal(aux.get_puntero())){
			cout << "Llegamos al goal! \n";
			return;
		}

		init_fwd_iter( &iter, aux.get_puntero() );
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	    	const int costo = aux.get_costo()+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, aux.get_puntero(), &hijo);
	    	const int *viejo_costo = state_map_get(mapa, &hijo);
            if (viejo_costo == NULL || *viejo_costo > costo ) {
				state_map_add(mapa, &hijo, costo);
				q.push(*(new nodo(hijo,*aux.get_puntero(),costo)));
			}
	    }
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

    ucsDDD(raiz);
}