#include <string>
#include <iostream>

using namespace std;

state_map_t* pdb1hanoi;
state_map_t* pdb2hanoi;
abstraction_t* abs1hanoi;
abstraction_t* abs2hanoi;

int heuristicaHanoi(state_t e){

	state_t abstracto1;
	state_t abstracto2;
	abstract_state(abs1hanoi,&e,&abstracto1);
	abstract_state(abs2hanoi,&e,&abstracto2);

	int valor1 = *state_map_get(pdb1hanoi,&abstracto1); 
	int valor2 = *state_map_get(pdb2hanoi,&abstracto2); 

	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
	}

}