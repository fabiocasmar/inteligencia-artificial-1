#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "nodo.hpp"

nodo::nodo(state_t x,nodo* y, int z,int r){
		puntero = x; 
		padre = y;
		costo =z;
		ruleid = r;
};

nodo::nodo(){
	costo = 0;
};
