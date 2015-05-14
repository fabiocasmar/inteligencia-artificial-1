#include <string>
#include <iostream>

using namespace std;

state_map_t cornerPdb;
state_map_t edgePdb;
abstraction_t cornerAbs;
abstraction_t edgeAbs;

int heuristicaRubik(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	abstract_state(cornerAbs,&e,&abstracto1); // Obtengo el estado abstracto asociado al estado dado
	abstract_state(edgeAbs,&e,&abstracto2);

	int valor1 =  state_map_get(cornerPdb,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(edgePdb,&abstracto2);  // Calculo el costo en el segundo pdb

	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
	}
}