#include <string>
#include <iostream>

using namespace std;

state_map_t* cornerPdb;
state_map_t* edge1Pdb;
state_map_t* edge2Pdb;
abstraction_t* cornerAbs;
abstraction_t* edge1Abs;
abstraction_t* edge2Abs;

int heuristicaRubik2(state_t e){
	state_t abstracto1;
	state_t abstracto2;
	abstract_state(cornerAbs,&e,&abstracto1);
	abstract_state(edge1Abs,&e,&abstracto2);

	int valor1 = *state_map_get(cornerPdb,&abstracto1);
	int valor2 = *state_map_get(edge1Pdb,&abstracto2); 

	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
	}
}

int heuristicaRubik3(state_t e){
	state_t abstracto1;
	state_t abstracto2;
	state_t abstracto3;
	abstract_state(cornerAbs,&e,&abstracto1); 
	abstract_state(edge1Abs,&e,&abstracto2);
	abstract_state(edge2Abs,&e,&abstracto3);

	int valor1 = *state_map_get(cornerPdb,&abstracto1); 
	int valor2 = *state_map_get(edge1Pdb,&abstracto2);  
	int valor3 = *state_map_get(edge2Pdb,&abstracto3);  

	if (valor1 > valor2){
		return max(valor1,valor3);
	}
	else{
		return max(valor2,valor3);
	}
}