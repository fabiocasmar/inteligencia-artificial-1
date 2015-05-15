#include <string>
#include <iostream>

using namespace std;

state_map_t pdb124puzzle;
state_map_t pdb224puzzle;       
state_map_t pdb324puzzle;
state_map_t pdb424puzzle;
state_map_t pdb524puzzle;

abstraction_t abs124puzzle;
abstraction_t abs224puzzle;
abstraction_t abs324puzzle;
abstraction_t abs424puzzle;
abstraction_t abs524puzzle;

int heuristica24Puzzle5(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	state_t abstracto3;
	state_t abstracto4;
	state_t abstracto5;

	abstract_state(abs124puzzle,&e,&abstracto1);
	abstract_state(abs224puzzle,&e,&abstracto2);
	abstract_state(abs324puzzle,&e,&abstracto3);
	abstract_state(abs424puzzle,&e,&abstracto4);
	abstract_state(abs524puzzle,&e,&abstracto5);

	int valor1 = state_map_get(pdb124puzzle,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb224puzzle,&abstracto2);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb324puzzle,&abstracto3);  // Calculo el costo en el tercer pdb
	int valor4 = state_map_get(pdb424puzzle,&abstracto4);
	int valor5 = state_map_get(pdb524puzzle,&abstracto5);

	return valor1+valor2+valor3+valor4+valor5;
}

int heuristica24Puzzle4(state_t e){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto1;
	state_t abstracto2;
	state_t abstracto3;
	state_t abstracto4;

	abstract_state(abs124puzzle,&e,&abstracto1);
	abstract_state(abs224puzzle,&e,&abstracto2);
	abstract_state(abs324puzzle,&e,&abstracto3);
	abstract_state(abs424puzzle,&e,&abstracto4);

	int valor1 = state_map_get(pdb124puzzle,&abstracto1); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb224puzzle,&abstracto2);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb324puzzle,&abstracto3);  // Calculo el costo en el tercer pdb
	int valor4 = state_map_get(pdb424puzzle,&abstracto4);

	return valor1+valor2+valor3+valor4;
}