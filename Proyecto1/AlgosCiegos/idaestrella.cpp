#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

const int MAXINT = std::numeric_limits<int>::max();

int busqueda(state_t e, int cota, int g, int (*funcion_h)(state_t)){
	int ruleid ;	
	int t = MAXINT;
    ruleid_iterator_t iter; 
    state_t hijo;
    int p;
    int f = g + funcion_h(e);


	if (f > g) 
		return f;

	if (is_goal(&e)){
	    cout << "Estado goal :  " << print_state(stdout,&e) << endl;
		return 0;
	}		

	init_fwd_iter( &iter, &e );
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
		apply_fwd_rule( ruleid, &e, &hijo );
		p = busqueda(hijo,cota,g+get_fwd_rule_cost(ruleid),funcion_h);
		if (p == 0){
			cout << print_state(stdout,&e) << endl;
			return p;
		}

		t = min(t,p);
    }
    return t;
}

void ida_estrella(state_t raiz, int (*funcion_h)(state_t)){
	int p;
	int cota = funcion_h(raiz);
	while ( true ){
		p = busqueda(raiz,cota,0,funcion_h);
		if(p == -1) break;
		if(p==0) break;
		cota = p;
	}
}

int main(){
	char estadoIni[999];
    ssize_t nchars;
    state_t raiz;

	cout << "Please enter a state followed by ENTER: \n";
	cin.getline(estadoIni,999,'\n');
	
	nchars = read_state(estadoIni,&raiz);
    if (nchars <= 0) {
		cout << "Error: invalid state entered.\n";
		return 0; 
    }

    //ida_estrella(raiz);
}