#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

void bfsDDD(state_t state){
	queue<state_t> q;
	int ruleid ;
    ruleid_iterator_t iter; 
    int hist, child_hist;
	hist = init_history;

	q.push(state);

	while (!(q.empty())) {
	    state_t child;
		state_t aux = q.front();
		q.pop();

		if (is_goal(&aux)){
			cout << "Llegamos al goal! \n";
			return;
		}

		init_fwd_iter( &iter, &aux );
	    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
			if (!(fwd_rule_valid_for_history(hist,ruleid))){
	    		cout << "Estoy eliminando un hijo de : " << print_state(stdout,&aux) << " " << endl;
				continue;
			}
			child_hist = next_fwd_history(hist,ruleid);
			apply_fwd_rule( ruleid, &aux, &child );
			q.push(child);
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

    bfsDDD(raiz);
}