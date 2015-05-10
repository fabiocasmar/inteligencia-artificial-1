#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <sys/time.h>
#include <fstream>

using namespace std;

const int MAXINT = std::numeric_limits<int>::max();
int totalNodos = 0;
int niveles = 0;

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

	if (costoAct > cota){
	    totalNodos++;
		return costoAct;
	}
	if (is_goal(&e)){
		return -1;
	}		

	init_fwd_iter( &iter, &e );
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
		apply_fwd_rule( ruleid, &e, &hijo );
		p = dfid_visita(hijo,cota,costoAct+get_fwd_rule_cost(ruleid));
		if (p < 0){
			niveles++;
			return p;
		}
		t = min(t,p);
    }
    return t;
}



int main(int argc,char* argv[]){
	string arch = argv[1];
	string linea;
	char estadoIni[999];
    ssize_t nchars;
    state_t raiz;

	ifstream myfile (argv[1]);
	while (getline(myfile,linea)){
		const char* c = linea.c_str();
		totalNodos = 0;
		niveles = 0;
		struct timeval t;
		gettimeofday(&t,NULL);
		double t1 = t.tv_sec+(t.tv_usec/1000000.0);

		nchars = read_state(c,&raiz);
	    if (nchars <= 0) {
			cout << "Error: invalid state entered.\n";
			return 0; 
	    }

	    dfid(raiz);

	    gettimeofday(&t,NULL);
	    double t2 = t.tv_sec+(t.tv_usec/1000000.0);
	    double segundos = t2-t1;

	    cout << print_state(stdout,&raiz) << " : " << "- " << niveles << " " << totalNodos << " " << segundos << " "; 
        cout << totalNodos/segundos << endl;
    }

    return 0;
}