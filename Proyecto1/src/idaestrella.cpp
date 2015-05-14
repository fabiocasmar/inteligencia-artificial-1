#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "./heuristicas/manhattan.cpp"
#include <sys/time.h>
#include <fstream>

using namespace std;

const int MAXINT = std::numeric_limits<int>::max();
int niveles = 0;
int totalNodos = 0;

int busqueda(state_t e, int cota, int g, int (*funcion_h)(state_t, int)){
	int ruleid ;	
	int t = MAXINT;
    ruleid_iterator_t iter; 
    state_t hijo;
    int p;
    int f = g + funcion_h(e,0);

	if (f > cota){
		totalNodos++;
		return f;
	}

	if (is_goal(&e)){
	    //cout << "Estado goal :  " << print_state(stdout,&e) << endl;
		return 0;
	}		

	init_fwd_iter( &iter, &e );
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
		apply_fwd_rule( ruleid, &e, &hijo );
		p = busqueda(hijo,cota,g+get_fwd_rule_cost(ruleid),funcion_h);
		if (p == 0){
			niveles++;
			return p;
		}
		t = min(t,p);
    }
    return t;
}

void ida_estrella(state_t raiz, int (*funcion_h)(state_t,int)){
	int p;
	int cota = funcion_h(raiz,0);
	while ( true ){
		p = busqueda(raiz,cota,0,funcion_h);
		if(p == -1) break;
		if(p == 0) break;
		cota = p;
	}
}

int main(int argc,char* argv[]){

	if (argc < 2){
   		std::cerr << "Error : Ingrese un archivo de entrada al ejecutar el programa \n";
   		return 1;
   	}

	string linea;
    ssize_t nchars;
    state_t raiz;
    char* aux = NULL;


	ifstream myfile (argv[1]);

	if (myfile.is_open()){
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
		    aux = new char[nchars+1];
		    sprint_state(aux,nchars+1,&raiz);

		    ida_estrella(raiz,calcularManhattan);

		    gettimeofday(&t,NULL);
		    double t2 = t.tv_sec+(t.tv_usec/1000000.0);
		    double segundos = t2-t1;

		    cout << aux << " : " << "- " << niveles << " " << totalNodos << " " << segundos << " "; 
	        cout << totalNodos/segundos << endl;
	        delete [] aux;
		}
	}
	else{
		std::cerr << "Error : El archivo no existe \n";
		return 1;
	}
}