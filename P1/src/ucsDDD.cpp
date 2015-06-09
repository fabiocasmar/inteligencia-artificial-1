#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "./extras/nodo.hpp"
#include <sys/time.h>
#include <fstream>

using namespace std;

int totalNodos = 0;
int niveles = 0;

struct orden{
    bool operator()(nodo *a, nodo *b){
        return a->costo > b->costo;
    }
};

nodo* ucsDDD(state_t state){
	priority_queue<nodo*,vector<nodo*>, orden> q;
	int ruleid, costo;
    ruleid_iterator_t iter; 
	state_map_t *mapa = new_state_map();
	nodo* nodoRaiz = new nodo(state,NULL,1,0);
	q.push(nodoRaiz);

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.top();
		q.pop();
		
		if (is_goal(&aux->puntero)){
			return aux;
		}

		init_fwd_iter( &iter, &aux->puntero);
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ) {
	    	int costo = aux->costo + get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	    	int viejo_costo = *(state_map_get(mapa, &hijo));
            if (viejo_costo == NULL || viejo_costo > costo ) {
            	nodo *nodoAux = new nodo(hijo,aux,costo,ruleid);
				state_map_add(mapa, &hijo, costo);
				totalNodos++;
				q.push(nodoAux);
			}
	    }
	}
	return NULL;
}

void calcularNiveles(nodo* n){
	if (n == NULL){
		return;
	}
	
	niveles++;
	calcularNiveles(n->padre);
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
				cout << "Error: El estado introducido es inválido " << endl;
				return 1; 
		    }
		    aux = new char[nchars+1];
		    sprint_state(aux,nchars+1,&raiz);
			
		    nodo* salida = ucsDDD(raiz);
		    calcularNiveles(salida);
			
		    gettimeofday(&t,NULL);
		    double t2 = t.tv_sec+(t.tv_usec/1000000.0);
		    double segundos = t2-t1;
		    
		    if (salida == NULL){
		    	cout << aux << " : " << "- No hay solución " << totalNodos << " " << segundos << " ";
		    } else {
		    	cout << aux << " : " << "- " << niveles << " " << totalNodos << " " << segundos << " "; 
		    }
	        cout << totalNodos/segundos << endl;
	        delete [] aux;

		}
	}
	else{
		std::cerr << "Error : El archivo no existe \n";
		return 1;
	}
}