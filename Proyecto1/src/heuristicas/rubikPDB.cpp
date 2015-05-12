#include <string>
#include <iostream>

using namespace std;

state_map_t cornerPdb;
state_map_t edgePdb;

int heuristicaRubik(abstraction_t* abs,state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto;
	abstract_state(abs,&e,&abstracto); // Obtengo el estado abstracto asociado al estado dado

	int valor1 =  state_map_get(cornerPdb,&abstracto); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(edgePdb,&abstracto);  // Calculo el costo en el segundo pdb

	if (valor1 > valor2){
		return valor1;
	}
	else{
		return valor2;
	}
}