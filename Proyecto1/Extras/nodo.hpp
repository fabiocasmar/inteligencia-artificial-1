#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

class nodo{
	public:
		state_t puntero; 
		nodo* padre; 
		int costo;
		int ruleid;
		nodo();
		nodo(state_t x, nodo* y, int z,int r);

};