#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

const int MAXINT = std::numeric_limits<int>::max();
double niveles[1000];

int dfid_visita(state_t,int,int);

void dfid(state_t raiz){
	int p;
	int cota = 0;

	while ( true ){
		dfid_visita(raiz,cota,0);
		cota = cota + 1;
		if(cota>1){
			cout << niveles[cota]/niveles[cota-1]<< endl;
		}
		cout << cota << " \t\t\t" << niveles[cota] << " \t\t\t";
	}
}

int dfid_visita(state_t e, int cota, int nivel){
	int ruleid ;	
	int t = MAXINT;
    ruleid_iterator_t iter; 
    state_t hijo;
    int p;

	if (nivel > cota){
		niveles[nivel]=niveles[nivel]+1.0;
		return nivel;
	}

	init_fwd_iter( &iter, &e );
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
		apply_fwd_rule( ruleid, &e, &hijo );
		p = dfid_visita(hijo,cota, nivel+1);
		t = min(t,p);
    }
    return t;
}



int main(){
	char estadoIni[999];
    ssize_t nchars;
    state_t raiz;

	//cout << "Please enter a state followed by ENTER: \n";
	cin.getline(estadoIni,999,'\n');
	
	nchars = read_state(estadoIni,&raiz);
    if (nchars <= 0) {
		cout << "Error: invalid state entered.\n";
		return 0; 
    }

    dfid(raiz);
}