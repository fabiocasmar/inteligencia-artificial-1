#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "nodo.hpp"

nodo::nodo(state_t x,nodo* y, int z){
		puntero = x; 
		padre = y;
		costo =z;
};

nodo::nodo(){
	costo = 0;
};
