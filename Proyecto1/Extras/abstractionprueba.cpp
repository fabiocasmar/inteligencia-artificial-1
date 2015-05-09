#include <string>
#include <iostream>

using namespace std;

int heuristicaRubik(abstraction_t* abs,state_t e,state_map_t cornerPdb,state_map_t edgePdb){
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

// Additive PDB
int heuristicaNPuzzle(abstraction_t* abs,state_t e,state_map_t pdb1,state_map_t pdb2,state_map_t pdb3){
	// Las pdb y la abstraction probablemente deberian ser globales

	state_t abstracto;
	abstract_state(abs,&e,&abstracto);

	int valor1 =  state_map_get(pdb1,&abstracto); // Calculo el costo en el primer pdb
	int valor2 = state_map_get(pdb2,&abstracto);  // Calculo el costo en el segundo pdb
	int valor3 = state_map_get(pdb3,&abstracto);  // Calculo el costo en el tercer pdb

	return valor1+valor2+valor3;
}

int main(){
	abstraction_t* abs1 = read_abstraction_from_file("absname.abst"); // Lee la abstraccion del archivo .abst generado

	FILE *f;
	f = fopen ("pdb2.txt" , "r"); // Es necesario que este archivo sea pasado como parametro al llamar a (dominio).dist para que lo genere
	state_map_t* mapa = read_state_map(f);
	fclose (f); // Lee la pdb generada y la guarda en un statemap

	state_t hola2;
	state_t hola;

	read_state("1 1 1 2 1",&hola);
	abstract_state(abs1,&hola,&hola2); // Devuelve el estado abstracto asociado al estado real (?)
	print_state(stdout,&hola2);

	int* x = state_map_get(mapa,&hola2);  // Parece dar igual que si pones &hola (?)
	cout << *x;
	printf("\n"); // Imprime el costo de llegar al goal desde dicho estado basandose en la abstraccion
}