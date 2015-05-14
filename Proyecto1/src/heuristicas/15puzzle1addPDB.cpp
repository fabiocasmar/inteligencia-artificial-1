#include <string>
#include <iostream>

using namespace std;

state_map_t pdb1npuzzle;
state_map_t pdb2npuzzle;       
state_map_t pdb3npuzzle;
abstraction_t abs1npuzzle;
abstraction_t abs2npuzzle;
abstraction_t abs3npuzzle;

int heuristicaNPuzzle(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	state_t abstracto3;
	abstract_state(abs1npuzzle,&e,&abstracto1);
	abstract_state(abs2npuzzle,&e,&abstracto2);
	abstract_state(abs3npuzzle,&e,&abstracto3);

	int valor1 =  state_map_get(pdb1npuzzle,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb2npuzzle,&abstracto2);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb3npuzzle,&abstracto3);  // Calculo el costo en el tercer pdb

	return valor1+valor2+valor3;
}