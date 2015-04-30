#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

const int MAXINT = std::numeric_limits<int>::max();

int dfid_visita(state_t,int,int);

void dfid(state_t raiz){
	int p;
	int cota = 0;

	while ( true ){
		p = dfid_visita(raiz,cota,0);
		if (p < 0){
			return;
		}
		cota = p;
	}
}

int dfid_visita(state_t e, int cota,int costoAct){
	int ruleid ;	
	int t = MAXINT;
    ruleid_iterator_t iter; 
    state_t hijo;
    int p;

	if (costoAct > cota) 
		return costoAct;
	if (is_goal(&e)){
	    cout << "Estado goal :  " << print_state(stdout,&e) << endl;
		return -1;
	}		

	init_fwd_iter( &iter, &e );
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
		apply_fwd_rule( ruleid, &e, &hijo );
		p = dfid_visita(hijo,cota,costoAct+get_fwd_rule_cost(ruleid));
		if (p < 0){
			cout << print_state(stdout,&e) << endl;
			return p;
		}
		t = min(t,p);
    }
    return t;
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

    dfid(raiz);
}