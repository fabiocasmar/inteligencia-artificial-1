#include <string>
#include <iostream>

using namespace std;

state_map_t* pdb1topspin;
state_map_t* pdb2topspin;
abstraction_t* abs1topspin;
abstraction_t* abs2topspin;

int heuristicaTopSpin(state_t e){

	state_t abstracto1;
	state_t abstracto2;
	abstract_state(abs1topspin,&e,&abstracto1);
	abstract_state(abs2topspin,&e,&abstracto2);

	int valor1 = *state_map_get(pdb1topspin,&abstracto1); 
	int valor2 = *state_map_get(pdb2topspin,&abstracto2); 

	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
	}

}