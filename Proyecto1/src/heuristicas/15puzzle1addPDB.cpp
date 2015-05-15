#include <string>
#include <iostream>

using namespace std;

state_map_t pdb115puzzle;
state_map_t pdb215uzzle;       
state_map_t pdb315uzzle;
abstraction_t abs115puzzle;
abstraction_t abs215puzzle;
abstraction_t abs315puzzle;

int heuristica15Puzzle3(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	state_t abstracto3;
	abstract_state(abs115puzzle,&e,&abstracto1);
	abstract_state(abs215puzzle,&e,&abstracto2);
	abstract_state(abs315puzzle,&e,&abstracto3);

	int valor1 =  state_map_get(pdb115puzzle,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb215puzzle,&abstracto2);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb315puzzle,&abstracto3);  // Calculo el costo en el tercer pdb

	return valor1+valor2+valor3;
}

int heuristica15<Puzzle2(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	abstract_state(abs115puzzle,&e,&abstracto1);
	abstract_state(abs215puzzle,&e,&abstracto2);

	int valor1 =  state_map_get(pdb115puzzle,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb215puzzle,&abstracto2);  // Calculo el costo en el segundo pdb

	return valor1+valor2+valor3;
}