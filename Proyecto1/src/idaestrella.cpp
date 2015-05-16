#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <sys/time.h>
#include "./extras/nodo.hpp"
#include "./heuristicas/manhattan.cpp"
#include "./heuristicas/rubikPDB.cpp"
#include "./heuristicas/15puzzle1addPDB.cpp"
#include "./heuristicas/24puzzle1addPDB.cpp"
#include "./heuristicas/heuristicahanoi.cpp"
#include "./heuristicas/heuristicatopspin.cpp"
#include <fstream>
#include <limits>

using namespace std;

const int MAXINT = numeric_limits<int>::max();
int niveles = 0;
int totalNodos = 0;

int busqueda(state_t e, int cota, int g, int (*funcion_h)(state_t)){
	int ruleid ;	
	int t = MAXINT;
    ruleid_iterator_t iter; 
    state_t hijo;
    int p;
    int f = g + funcion_h(e);

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

void ida_estrella(state_t raiz, int (*funcion_h)(state_t)){
	int p;
	int cota = funcion_h(raiz);
	while ( true ){
		p = busqueda(raiz,cota,0,funcion_h);
		if(p == -1) break;
		if(p == 0) break;
		cota = p;
	}
}

int main(int argc,char* argv[]){
	int (*funcion_g)(state_t);
	if (argc < 3){
   		std::cerr << "Error, la sitaxis es: archivo.txt nombre_problema (manhattan|pdb modo_pdb) \n";
   		return 1;
   	}else if((argc==5)&&(strcmp(argv[3],"manhattan")==0)){
		std::cerr << "Error, la sitaxis es: archivo.txt nombre_problema (manhattan|pdb modo_pdb) \n";
   		return 1;
   	}else if(((strcmp(argv[2],"15puzzle1")==0)||
   				(strcmp(argv[2],"15puzzle2")==0)||
   					(strcmp(argv[2],"24puzzle1")==0)||
   						(strcmp(argv[2],"24puzzle2")==0))&&(argc < 4)){
		std::cerr << "Error, la sitaxis es: archivo.txt nombre_problema (manhattan|pdb modo_pdb) \n";
   		return 1;
	}

  //  	Codigo para leer los pdbs y abstracciones segun el problema :
  //    NOTA : Todas las variables de nombre absX(problema) y pdbX(problema) son globales en sus
  //    respectivas heuristicas
	if (strcmp(argv[2],"15puzzle1")==0){
		if (strcmp(argv[3],"pdb")==0){
			if (strcmp(argv[4],"555")==0){

				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle1/555/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle1/555/pdb2.abst");
			    abs315puzzle = read_abstraction_from_file("./PDBs/15puzzle1/555/pdb3.abst");
				FILE *f;
				f = fopen ("./PDBs/15puzzle1/555/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle1/555/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle1/555/pdb3.txt" , "r"); 
				pdb315puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle3;
			}else if (strcmp(argv[4],"663")==0){
				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle1/663/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle1/663/pdb2.abst");
			    abs315puzzle = read_abstraction_from_file("./PDBs/15puzzle1/663/pdb3.abst");

				FILE *f;

				f = fopen ("./PDBs/15puzzle1/663/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle1/663/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle1/663/pdb3.txt" , "r"); 
				pdb315puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle3;
			}else if(strcmp(argv[4],"78")==0){
				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle1/78/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle1/78/pdb2.abst");

				FILE *f;

				f = fopen ("./PDBs/15puzzle1/78/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle1/78/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle2;
			}else{
				std::cerr << "Error, la sitaxis es: archivo.txt nombre_problema (manhattan|pdb modo_pdb) \n";
					return 1;
			}
  	    }else if(strcmp(argv[3],"manhattan")==0){
  	    	funcion_g = calcularManhattan15;
  	    }
	}else if (strcmp(argv[2],"15puzzle2")==0){
		if (strcmp(argv[3],"pdb")==0){
			if (strcmp(argv[4],"555")==0){
				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle2/555/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle2/555/pdb2.abst");
			    abs315puzzle = read_abstraction_from_file("./PDBs/15puzzle2/555/pdb3.abst");
				FILE *f;
				f = fopen ("./PDBs/15puzzle2/555/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle2/555/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle2/555/pdb3.txt" , "r"); 
				pdb315puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle3;
			}else if (strcmp(argv[4],"663")==0){
				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle2/663/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle2/663/pdb2.abst");
			    abs315puzzle = read_abstraction_from_file("./PDBs/15puzzle2/663/pdb3.abst");

				FILE *f;

				f = fopen ("./PDBs/15puzzle2/663/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle2/663/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle2/663/pdb3.txt" , "r"); 
				pdb315puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle3;
			}else if (strcmp(argv[4],"78")==0){
				abs115puzzle = read_abstraction_from_file("./PDBs/15puzzle2/78/pdb1.abst");
			    abs215puzzle = read_abstraction_from_file("./PDBs/15puzzle2/78/pdb2.abst");

				FILE *f;

				f = fopen ("./PDBs/15puzzle2/78/pdb1.txt" , "r"); 
				pdb115puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/15puzzle2/78/pdb2.txt" , "r"); 
				pdb215puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica15Puzzle2;
			}else{
				std::cerr << "Error, la sitaxis es: archivo.txt nombre_problema (manhattan|pdb modo_pdb) \n";
					return 1;
			}
  	    }else if(strcmp(argv[3],"manhattan")==0){
  	    	funcion_g = calcularManhattan15;
  	    }
	}else if (strcmp(argv[2],"24puzzle1")==0){
		if (strcmp(argv[3],"pdb")==0){
			if (strcmp(argv[4],"55554")==0){

				abs124puzzle = read_abstraction_from_file("./PDBs/24puzzle1/55554/pdb1.abst");
			    abs224puzzle = read_abstraction_from_file("./PDBs/24puzzle1/55554/pdb2.abst");
			    abs324puzzle = read_abstraction_from_file("./PDBs/24puzzle1/55554/pdb3.abst");
			    abs424puzzle = read_abstraction_from_file("./PDBs/24puzzle1/55554/pdb4.abst");
			    abs524puzzle = read_abstraction_from_file("./PDBs/24puzzle1/55554/pdb5.abst");
			    FILE *f;
				f = fopen ("./PDBs/24puzzle1/55554/pdb1.txt" , "r"); 
				pdb124puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/55554/pdb2.txt" , "r"); 
				pdb224puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/55554/pdb3.txt" , "r"); 
				pdb324puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/55554/pdb4.txt" , "r"); 
				pdb424puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/55554/pdb5.txt" , "r"); 
				pdb524puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica24Puzzle5;
			}else if (strcmp(argv[4],"6666")==0){
				abs124puzzle = read_abstraction_from_file("./PDBs/24puzzle1/6666/pdb1.abst");
			    abs224puzzle = read_abstraction_from_file("./PDBs/24puzzle1/6666/pdb2.abst");
			    abs324puzzle = read_abstraction_from_file("./PDBs/24puzzle1/6666/pdb3.abst");
			    abs424puzzle = read_abstraction_from_file("./PDBs/24puzzle1/6666/pdb4.abst");
			    FILE *f;
				f = fopen ("./PDBs/24puzzle1/6666/pdb1.txt" , "r"); 
				pdb124puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/6666/pdb2.txt" , "r"); 
				pdb224puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/6666/pdb3.txt" , "r"); 
				pdb324puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle1/6666/pdb4.txt" , "r"); 
				pdb424puzzle = read_state_map(f);
				fclose (f);

				funcion_g = heuristica24Puzzle4;
			}
		}else if(strcmp(argv[3],"manhattan")==0){
			funcion_g = calcularManhattan24;
  	    }
  	}else if (strcmp(argv[2],"24puzzle2")==0){
		if (strcmp(argv[3],"pdb")==0){
			if (strcmp(argv[4],"55554")==0){
				abs124puzzle = read_abstraction_from_file("./PDBs/24puzzle2/55554/pdb1.abst");
			    abs224puzzle = read_abstraction_from_file("./PDBs/24puzzle2/55554/pdb2.abst");
			    abs324puzzle = read_abstraction_from_file("./PDBs/24puzzle2/55554/pdb3.abst");
			    abs424puzzle = read_abstraction_from_file("./PDBs/24puzzle2/55554/pdb4.abst");
			    abs524puzzle = read_abstraction_from_file("./PDBs/24puzzle2/55554/pdb5.abst");
			    FILE *f;
				f = fopen ("./PDBs/24puzzle2/55554/pdb1.txt" , "r"); 
				pdb124puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/55554/pdb2.txt" , "r"); 
				pdb224puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/55554/pdb3.txt" , "r"); 
				pdb324puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/55554/pdb4.txt" , "r"); 
				pdb424puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/55554/pdb5.txt" , "r"); 
				pdb524puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica24Puzzle5;
			}else if (strcmp(argv[4],"6666")==0){
				abs124puzzle = read_abstraction_from_file("./PDBs/24puzzle2/6666/pdb1.abst");
			    abs224puzzle = read_abstraction_from_file("./PDBs/24puzzle2/6666/pdb2.abst");
			    abs324puzzle = read_abstraction_from_file("./PDBs/24puzzle2/6666/pdb3.abst");
			    abs424puzzle = read_abstraction_from_file("./PDBs/24puzzle2/6666/pdb4.abst");
			    FILE *f;
				f = fopen ("./PDBs/24puzzle2/6666/pdb1.txt" , "r"); 
				pdb124puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/6666/pdb2.txt" , "r"); 
				pdb224puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/6666/pdb3.txt" , "r"); 
				pdb324puzzle = read_state_map(f);
				fclose (f);
				f = fopen ("./PDBs/24puzzle2/6666/pdb4.txt" , "r"); 
				pdb424puzzle = read_state_map(f);
				fclose (f);
				funcion_g = heuristica24Puzzle4;
			}
		}else if(strcmp(argv[3],"manhattan")==0){
			funcion_g = calcularManhattan24;
  	    }
  	}else if (strcmp(argv[2],"rubik2")==0){ 
     	cornerAbs = read_abstraction_from_file("./PDBs/Rubik2/pdb1.abst");
   		edge1Abs = read_abstraction_from_file("./PDBs/Rubik2/pdb2.abst");
   		FILE *f;
		f = fopen ("./PDBs/Rubik2/pdb1.txt" , "r"); 
		cornerPdb = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Rubik2/pdb2.txt" , "r"); 
		edge1Pdb = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaRubik2;
	}else if (strcmp(argv[2],"rubik3")==0){ 
     	cornerAbs = read_abstraction_from_file("./PDBs/Rubik3/pdb1.abst");
   		edge1Abs = read_abstraction_from_file("./PDBs/Rubik3/pdb2.abst");
   		edge2Abs = read_abstraction_from_file("./PDBs/Rubik3/pdb3.abst");
   		FILE *f;
		f = fopen ("./PDBs/Rubik3/pdb1.txt" , "r"); 
		cornerPdb = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Rubik3/pdb2.txt" , "r"); 
		edge1Pdb = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Rubik3/pdb3.txt" , "r"); 
		edge2Pdb = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaRubik3;
	}else if (strcmp(argv[2],"hanoi12")==0){ 
     	abs1hanoi = read_abstraction_from_file("./PDBs/Hanoi12/pdb1.abst");
   		abs2hanoi = read_abstraction_from_file("./PDBs/Hanoi12/pdb2.abst");
   		FILE *f;
		f = fopen ("./PDBs/Hanoi12/pdb1.txt" , "r"); 
		pdb1hanoi = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Hanoi12/pdb2.txt" , "r"); 
		pdb2hanoi = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaHanoi;
	}else if (strcmp(argv[2],"hanoi14")==0){ 
     	abs1hanoi = read_abstraction_from_file("./PDBs/Hanoi14/pdb1.abst");
   		abs2hanoi = read_abstraction_from_file("./PDBs/Hanoi14/pdb2.abst");
   		FILE *f;
		f = fopen ("./PDBs/Hanoi14/pdb1.txt" , "r"); 
		pdb1hanoi = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Hanoi14/pdb2.txt" , "r"); 
		pdb2hanoi = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaHanoi;	
	}else if (strcmp(argv[2],"hanoi16")==0){ 
     	abs1hanoi = read_abstraction_from_file("./PDBs/Hanoi16/pdb1.abst");
   		abs2hanoi = read_abstraction_from_file("./PDBs/Hanoi16/pdb2.abst");
   		FILE *f;
		f = fopen ("./PDBs/Hanoi16/pdb1.txt" , "r"); 
		pdb1hanoi = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/Hanoi16/pdb2.txt" , "r"); 
		pdb2hanoi = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaHanoi;
	}else if (strcmp(argv[2],"topSpin12")==0){
		abs1topspin = read_abstraction_from_file("./PDBs/TopSpin12/pdb1.abst");
   		abs2topspin = read_abstraction_from_file("./PDBs/TopSpin12/pdb2.abst");
		FILE *f;
		f = fopen ("./PDBs/TopSpin12/pdb1.txt" , "r"); 
		pdb1topspin = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/TopSpin12/pdb2.txt" , "r"); 
		pdb2topspin = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaTopSpin;
   }else if (strcmp(argv[2],"topSpin14")==0){
   		abs1topspin = read_abstraction_from_file("./PDBs/TopSpin14/pdb1.abst");
   		abs2topspin = read_abstraction_from_file("./PDBs/TopSpin14/pdb2.abst");
		FILE *f;
		f = fopen ("./PDBs/TopSpin14/pdb1.txt" , "r"); 
		pdb1topspin = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/TopSpin14/pdb2.txt" , "r"); 
		pdb2topspin = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaTopSpin;
   }else if (strcmp(argv[2],"topSpin16")==0){
   		abs1topspin = read_abstraction_from_file("./PDBs/TopSpin16/pdb1.abst");
   		abs2topspin = read_abstraction_from_file("./PDBs/TopSpin16/pdb2.abst");
		FILE *f; 
		f = fopen ("./PDBs/TopSpin16/pdb1.txt" , "r"); 
		pdb1topspin = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/TopSpin16/pdb2.txt" , "r"); 
		pdb2topspin = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaTopSpin;
   }else if (strcmp(argv[2],"topSpin17")==0){
   		abs1topspin = read_abstraction_from_file("./PDBs/TopSpin17/pdb1.abst");
   		abs2topspin = read_abstraction_from_file("./PDBs/TopSpin17/pdb2.abst");
		FILE *f;
		f = fopen ("./PDBs/TopSpin17/pdb1.txt" , "r"); 
		pdb1topspin = read_state_map(f);
		fclose (f);
		f = fopen ("./PDBs/TopSpin17/pdb2.txt" , "r"); 
		pdb2topspin = read_state_map(f);
		fclose (f);
		funcion_g = heuristicaTopSpin;
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

		    ida_estrella(raiz,funcion_g);

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