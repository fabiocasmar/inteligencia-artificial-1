#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "nodo.hpp"

nodo::nodo(state_t x, state_t y, int z){
		puntero = x; 
		padre = y;
		costo =z;
};
nodo::nodo(){
	costo = 0;
};

state_t* nodo::get_puntero(){
	return &puntero;
};

state_t* nodo::get_padre(){
	return &padre;
};

int nodo::get_costo(){
	return costo;
};

void nodo::set_puntero(state_t x){
	puntero = x;
};
void nodo::set_padre(state_t x){
	padre = x;
};
void nodo::set_costo(int x){
	costo = x;
};
