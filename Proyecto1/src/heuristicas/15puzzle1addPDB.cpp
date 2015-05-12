#include <string>
#include <iostream>

state_map_t pdb1;
state_map_t pdb2;
state_map_t pdb3;

int heuristicaNPuzzle(abstraction_t* abs,state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto;
	abstract_state(abs,&e,&abstracto);

	int valor1 =  state_map_get(pdb1,&abstracto); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb2,&abstracto);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb3,&abstracto);  // Calculo el costo en el tercer pdb

	return valor1+valor2+valor3;
}