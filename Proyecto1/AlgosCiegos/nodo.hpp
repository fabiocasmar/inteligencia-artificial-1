#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

class nodo{
	private:
		state_t puntero;
		state_t padre;
		int costo;
	public:
		nodo();
		nodo(state_t x, state_t y, int z);
		state_t* get_puntero();
		state_t* get_padre();
		int get_costo();
		void set_puntero(state_t x);
		void set_padre(state_t x);
		void set_costo(int x);

};