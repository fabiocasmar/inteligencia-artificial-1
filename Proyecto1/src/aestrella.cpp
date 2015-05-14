#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "./extras/nodo.hpp"
#include "./heuristicas/manhattan.cpp"
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

 class NuestraPila : public priority_queue<nodo*,vector<nodo*>, orden>
{
public:
    typedef typename
    priority_queue<nodo*,vector<nodo*>,
    				orden>::container_type::const_iterator const_iterator;
    nodo* find(state_t val)
    {
        auto first = this->c.begin();
        auto last = this->c.end();
        nodo temp;
        while (first!=last) {
        	temp = **first;
            if (compare_states(&temp.puntero,&val)==0) return *first;
            ++first;
        }
        return *last;
    }
};

nodo* aestrella(state_t state, int (*funcion_g)(state_t,int)){
	NuestraPila q;
	int ruleid, costo, viejo_costo, estimado;
    ruleid_iterator_t iter; 
	state_map_t *mapa_costo = new_state_map();
	state_map_t *mapa_estado = new_state_map();
	nodo* nodoRaiz = new nodo(state,NULL,1,0);
	q.push(nodoRaiz);
	state_map_add(mapa_costo, &state, 1);
	nodo *nodoAux;

	while (!(q.empty())) {
	    state_t hijo;
		nodo* aux = q.top();
		q.pop();
		state_map_add(mapa_estado, &aux->puntero, 2);

		if (is_goal(&aux->puntero)){
			free(mapa_estado);
			free(mapa_costo);
			return aux;
		}

		init_fwd_iter( &iter, &aux->puntero);
	    while(( ruleid = next_ruleid( &iter ) ) >= 0 ){
	    	costo = *(state_map_get(mapa_costo, &aux->puntero))
	    											+get_fwd_rule_cost(ruleid);
	    	apply_fwd_rule(ruleid, &aux->puntero, &hijo);
	    	if((state_map_get(mapa_costo, &hijo))!=NULL){
	    		viejo_costo = *(state_map_get(mapa_costo, &hijo));
	    	}else{
	    		viejo_costo = 0;
	    	}
	    	nodoAux = new nodo(hijo,aux,costo,ruleid);
	    	if((state_map_get(mapa_estado, &hijo))!=NULL) 
	    		if(*(state_map_get(mapa_estado, &hijo))==2)continue;
            if ((state_map_get(mapa_estado, &hijo)==NULL)||
            		(viejo_costo > costo)){
            	estimado = costo+funcion_g(hijo,0);
            	state_map_add(mapa_costo, &hijo, costo);
				if(state_map_get(mapa_estado, &hijo)==NULL){
					state_map_add(mapa_estado, &hijo, 1);
					totalNodos++;
					q.push(nodoAux);
				}else{
					nodoAux = q.find(hijo);
					(*nodoAux).padre=aux;
					(*nodoAux).costo=estimado;
				}
			}
	    }
	}
	cout << "No hay camino hasta el goal \n";
	return NULL;
}

// void imprimirCamino(nodo* n){
// 	if (n == NULL){
// 		return;
// 	}
// 	cout << print_state(stdout,&n->puntero) << endl;
// 	imprimirCamino(n->padre);
// }

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


  //  	Codigo para leer los pdbs y abstracciones segun el problema :
  //    NOTA : Todas las variables de nombre absX(problema) y pdbX(problema) son globales en sus
  //    respectivas heuristicas
  //  	if (argumento2 == "15puzzle1"){
		// abs115puzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb1.abst");
		// abs215puzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb2.abst");
		// abs315puzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb3.abst");

		// FILE *f;

		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb1.txt" , "r"); 
		// pdb115puzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb2.txt" , "r"); 
		// pdb215puzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb3.txt" , "r"); 
		// pdb315puzzle = read_state_map(f);
		// fclose (f);
  //   }
  //   // Aqui deberian venir los de 15puzzle2,24puzzle1,24puzzle2 y rubik2 y rubik3, pero aun no tenemos pdbs de eso
  //  	   else if (argumento2 == "24puzzle1"){
  //  	    abs124puzzle = read_abstraction_from_file("../PDBs/24puzzle1/(Argumento3)/pdb1.abst");
		// abs224puzzle = read_abstraction_from_file("../PDBs/24puzzle1/(Argumento3)/pdb2.abst");
		// abs324puzzle = read_abstraction_from_file("../PDBs/24puzzle1/(Argumento3)/pdb3.abst");
		// abs424puzzle = read_abstraction_from_file("../PDBs/24puzzle1/(Argumento3)/pdb4.abst");
		// abs524puzzle = read_abstraction_from_file("../PDBs/24puzzle1/(Argumento3)/pdb5.abst");

		// FILE *f;

		// f = fopen ("../PDBs/24puzzle1/(Argumento3)/pdb1.txt" , "r"); 
		// pdb124puzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/24puzzle1/(Argumento3)/pdb2.txt" , "r"); 
		// pdb224puzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/24puzzle1/(Argumento3)/pdb3.txt" , "r"); 
		// pdb324puzzle = read_state_map(f);
		// fclose (f);
	 //    f = fopen ("../PDBs/24puzzle1/(Argumento3)/pdb4.txt" , "r"); 
		// pdb424puzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/24puzzle1/(Argumento3)/pdb5.txt" , "r"); 
		// pdb524puzzle = read_state_map(f);
		// fclose (f);

  //  	   }
  //   else if (argumento2 == "Hanoi"){ 
  //   	// NOTA : Si existe manera de verificar si el nombre dice "HanoiXX" donde XX es un numero 
  //   	// 12,14,,16 o 18. Entonces se puede hacer solo este if, y que dentro de cada carpeta
  //   	// los archivos se llamen pdb1 y pdb2, de manera de que basta con este if para leer cualquier
  //   	// caso de hanoi...Si no, es necesario hacer un if para cada Hanoi.
  //   	abs1hanoi = read_abstraction_from_file("../PDBs/HanoiX/pdb1.abst");
  //  		abs2hanoi = read_abstraction_from_file("../PDBs/HanoiX/pdb2.abst");

  //  		FILE *f 

		// f = fopen ("../PDBs/HanoiX/pdb1.txt" , "r"); 
		// pdb1hanoi = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/HanoiX/pdb2.txt" , "r"); 
		// pdb2hanoi = read_state_map(f);
		// fclose (f);
  //   }	
  //   else if (argumento2 == "topSpin"){
  //   	// NOTA : Lo mismo aqui, se es posible agarrar topSpin separado de XX, se puede dejar solo este if
  //   	// y para cada caso abrir los archivos en la carpeta TopSpinXX en vez de hacer varios ifs.
  //   	abs1topspin = read_abstraction_from_file("../PDBs/TopSpinX/pdb1.abst");
  //  		abs2topspin = read_abstraction_from_file("../PDBs/TopSpinX/pdb2.abst");

  //  		FILE *f 

		// f = fopen ("../PDBs/TopSpinX/pdb1.txt" , "r"); 
		// pdb1hanoi = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/TopSpinX/pdb2.txt" , "r"); 
		// pdb2hanoi = read_state_map(f);
		// fclose (f);
  //   }


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
				cout << "Error: El estado introducido es invalido " << endl;
				return 1; 
		    }

		    aux = new char[nchars+1];
		    sprint_state(aux,nchars+1,&raiz);

		    nodo* salida = aestrella(raiz,calcularManhattan);
		    calcularNiveles(salida);
		    
		    gettimeofday(&t,NULL);
		    double t2 = t.tv_sec+(t.tv_usec/1000000.0);
		    double segundos = t2-t1;

		    cout << aux << " : " << "- " << niveles << " " << totalNodos << " " << segundos << " "; 
	        cout << totalNodos/segundos << endl;
	        free(salida);
	        delete [] aux;
	        
		}
	}
	else{
		std::cerr << "Error : El archivo no existe \n";
		return 1;
	}

    
}