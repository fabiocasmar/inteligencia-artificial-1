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

   	//  	Codigo para leer los pdbs y abstracciones segun el problema :
  //    NOTA : Todas las variables de nombre absX(problema) y pdbX(problema) son globales en sus
  //    respectivas heuristicas
  //  	if (argumento2 == "15puzzle1"){
		// abs1npuzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb1.abst");
		// abs2npuzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb2.abst");
		// abs3npuzzle = read_abstraction_from_file("../PDBs/15puzzle1/(Argumento3)/pdb3.abst");

		// FILE *f;

		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb1.txt" , "r"); 
		// pdb1npuzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb2.txt" , "r"); 
		// pdb2npuzzle = read_state_map(f);
		// fclose (f);
		// f = fopen ("../PDBs/15puzzle1/(Argumento3)/pdb3.txt" , "r"); 
		// pdb3npuzzle = read_state_map(f);
		// fclose (f);
  //   }
  //   // Aqui deberian venir los de 15puzzle2,24puzzle1,24puzzle2 y rubik2 y rubik3, pero aun no tenemos pdbs de eso
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