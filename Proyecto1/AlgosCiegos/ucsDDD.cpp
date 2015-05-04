#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

typedef pair < state_t,int > par;

struct orden{
    bool operator()(par const& a, par const& b) const
    {
        return a.second > b.second;
    }
};

void ucsDDD(state_t state){
	priority_queue<par,vector<par >, orden> q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa = new_state_map();

	q.push(make_pair(state,0));

	while (!(q.empty())) {
	    state_t hijo;
		pair<state_t, int> aux = q.top();
		q.pop();

		if (is_goal(&aux.first)){
			cout << "Llegamos al goal! \n";
			return;
		}

		init_fwd_iter( &iter, &aux.first );
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	    	const int costo = aux.second+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux.first, &hijo);
	    	const int *viejo_costo = state_map_get(mapa, &hijo );
            if (viejo_costo == NULL || *viejo_costo > costo ) {
				state_map_add(mapa, &hijo, costo);
				q.push(make_pair(hijo,costo));
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