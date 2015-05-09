#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
using namespace std;

/* Distancia Manhattan precalculada para cada tile.
 * Sea dist_manh[i][j], la posición i-ésima indica el
 * identificador del tile a buscar, la posición j-ésima
 * indica en qué lugar del tablero se encuentra el tile i.
 * dist_manh[i][j] indica la distancia manhattan del tile
 * i en la posición j hasta la posición goal de ese tile.
 */
int dist_manh[16][16] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4, 4, 3, 4, 5},
	{2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3, 5, 4, 3, 4},
	{3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2, 6, 5, 4, 3},
	{1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5},
	{2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4},
	{3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3},
	{4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2},
	{2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4},
	{3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3},
	{4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2},
	{5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1},
	{3, 4, 5, 6, 2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3},
	{4, 3, 4, 5, 3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2},
	{5, 4, 3, 4, 4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1},
	{6, 5, 4, 3, 5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0}
};

int dist_manh24[25][25] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 	{1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5, 4, 3, 4, 5, 6, 5, 4, 5, 6, 7}, 
 	{2, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5, 4, 3, 4, 5, 6, 5, 4, 5, 6}, 
 	{3, 2, 1, 0, 1, 4, 3, 2, 1, 2, 5, 4, 3, 2, 3, 6, 5, 4, 3, 4, 7, 6, 5, 4, 5}, 
 	{4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 6, 5, 4, 3, 2, 7, 6, 5, 4, 3, 8, 7, 6, 5, 4}, 
 	{1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7}, 
 	{2, 1, 2, 3, 4, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5, 4, 3, 4, 5, 6}, 
 	{3, 2, 1, 2, 3, 2, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5, 4, 3, 4, 5}, 
 	{4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 4, 3, 2, 1, 2, 5, 4, 3, 2, 3, 6, 5, 4, 3, 4}, 
 	{5, 4, 3, 2, 1, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 6, 5, 4, 3, 2, 7, 6, 5, 4, 3}, 
 	{2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 1, 2, 3, 4, 5, 2, 3, 4, 5, 6}, 
 	{3, 2, 3, 4, 5, 2, 1, 2, 3, 4, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4, 5}, 
 	{4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 4}, 
 	{5, 4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 4, 3, 2, 1, 2, 5, 4, 3, 2, 3}, 
 	{6, 5, 4, 3, 2, 5, 4, 3, 2, 1, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 6, 5, 4, 3, 2}, 
 	{3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 1, 2, 3, 4, 5}, 
 	{4, 3, 4, 5, 6, 3, 2, 3, 4, 5, 2, 1, 2, 3, 4, 1, 0, 1, 2, 3, 2, 1, 2, 3, 4}, 
 	{5, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 2, 3, 2, 1, 2, 3}, 
 	{6, 5, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 4, 3, 2, 1, 2}, 
 	{7, 6, 5, 4, 3, 6, 5, 4, 3, 2, 5, 4, 3, 2, 1, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1}, 
 	{4, 5, 6, 7, 8, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4}, 
 	{5, 4, 5, 6, 7, 4, 3, 4, 5, 6, 3, 2, 3, 4, 5, 2, 1, 2, 3, 4, 1, 0, 1, 2, 3}, 
 	{6, 5, 4, 5, 6, 5, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1, 2}, 
 	{7, 6, 5, 4, 5, 6, 5, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 0, 1}, 
 	{8, 7, 6, 5, 4, 7, 6, 5, 4, 3, 6, 5, 4, 3, 2, 5, 4, 3, 2, 1, 4, 3, 2, 1, 0}	
};

/*
 * Convierte un objeto de tipo state_t en un arreglo de enteros
 */
int* convEstado(state_t estado){
	int j = 0;
	char aux[38];
	int res[16];
	char* ptr = (char*)malloc(200*sizeof(char));

	sprint_state(aux,38,&estado);
	ptr = strtok(aux," ");
	
	while(ptr!=NULL){
		if(strcmp(ptr,"B")==0){
			res[j] = 0;
		} else {
			res[j] = atoi(ptr);
		}
		j = j + 1;
		ptr = strtok(NULL," ");		
	}
	for (int i = 0;i < 16; i++){
		//cout << res[i] << endl;
	}
	return &res[0];
}

int* convEstado24(state_t estado){
	int j = 0;
	char aux[65];
	int res[25];
	char* ptr = (char*)malloc(200*sizeof(char));

	sprint_state(aux,65,&estado);
	//cout << aux << endl;
	ptr = strtok(aux," ");
	
	while(ptr!=NULL){
		if(strcmp(ptr,"B")==0){
			res[j] = 0;
		} else {
			res[j] = atoi(ptr);
		}
		j = j + 1;
		ptr = strtok(NULL," ");		
	}
	for (int i = 0;i < 25; i++){
		//cout << res[i] << endl;
	}
	return &res[0];	
}

/*
 * Calcula la distancia manhattan de una configuración de tablero. prob = 1 si
 * es 24-puzzle, prob = 0 si es 15-puzzle
 */
int calcularManhattan(state_t estado, int prob){
	int res = 0;
	int* tablero = (int*)malloc(sizeof(int));

	if (prob==0){
		tablero = convEstado(estado);
		for(int i = 0;i < 16; i++){
			res = res + dist_manh[tablero[i]][i];
		}
	} else {
		tablero = convEstado24(estado);
		for(int i = 0;i < 25; i++){
			res = res + dist_manh24[tablero[i]][i];
		}
	}
	return res;
}

/*

int main(){
	char estadoIni[999];
    ssize_t nchars;
    state_t raiz;
    int res;

	cout << "Introduzca un estado y presione ENTER : " << endl;
	cin.getline(estadoIni,999,'\n');
	
	nchars = read_state(estadoIni,&raiz);
    if (nchars <= 0) {
		cout << "Error: El estado introducido es invalido " << endl;
		return 0; 
    }
    res = calcularManhattan(raiz,0);
    cout << "Distancia Manhattan: " << res << endl;
}
*/