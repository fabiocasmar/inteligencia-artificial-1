#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include "nodo.hpp"

using namespace std;


bool podarParalelos(state_t hijo,int ruleid,nodo* padre){
    string labelHijo = get_fwd_rule_label(ruleid);
    string labelPadre = get_fwd_rule_label(padre->ruleid);

    if (labelHijo[2] == labelPadre[2]){
        // Si la direccion del movimiento del hijo y del padre son iguales...
        // Chequea a ver si el hijo mueve una cara fuerte y el padre la debil asociada...
        // de ser asi, el movimiento no pasa y no se expande ese hijo
        if (((labelHijo[0] == 'U') and (labelPadre[0] == 'D'))
            or ((labelHijo[0] == 'R') and (labelPadre[0] == 'L'))
                or ((labelHijo[0] == 'F') and (labelPadre[0] == 'B'))){
            // cout << "HIJO : \n";
            // cout << print_state(stdout,&hijo) << " " << labelHijo << endl;
            // cout << "PADRE : \n";
            // cout << print_state(stdout,&padre->puntero) << labelPadre << endl;
            return true;
        }
    } // El else if the abajo es para evitar que movimientos seguidos contrarios pasen. Se puede quitar (?)
    else if ((((labelHijo[2] == 'W') and (labelPadre[2] == 'C')) 
                or ((labelHijo[2] == 'C') and (labelPadre[2] == 'W'))
                    or ((labelHijo[2] == '8') and (labelPadre[2] == '8')))
                        and (labelPadre[0] == labelHijo[0])){
            return true;
    }

    return false;
}

nodo* bfsDDD(state_t state){
    queue<nodo*> q;
    int ruleid ;
    ruleid_iterator_t iter; 
    // state_map_t *mapa = new_state_map();
    nodo* nodoRaiz = new nodo(state,NULL,1,0);
    q.push(nodoRaiz);

    while (!(q.empty())) {
        state_t hijo;
        nodo* aux = q.front();
        q.pop();

        if (is_goal(&aux->puntero)){
            cout << "Llegamos al goal! \n";
            return aux;
        }

        init_fwd_iter( &iter, &aux->puntero );
        while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
            apply_fwd_rule(ruleid, &aux->puntero, &hijo);
            // const int *visitado = state_map_get(mapa, &hijo );
            if (podarParalelos(hijo,ruleid,aux)){
                // cout << "Estoy eliminando duplicados paralelos!" << endl;
                continue;
            }
            nodo *nodoAux = new nodo(hijo,aux,1,ruleid);
            // state_map_add(mapa, &hijo, 1,ruleid);
            q.push(nodoAux);
        }
        // state_map_add(mapa,&aux->puntero,2);
    }

    cout << "No hay camino hasta el goal \n";
}

void imprimirCamino(nodo* n){
    if (n == NULL){
        return;
    }
    cout << print_state(stdout,&n->puntero) << endl;
    imprimirCamino(n->padre);
}

int main(){
    char estadoIni[999];
    ssize_t nchars;
    state_t raiz;

    cout << "Introduzca un estado y presione ENTER : " << endl;
    cin.getline(estadoIni,999,'\n');
    
    nchars = read_state(estadoIni,&raiz);
    if (nchars <= 0) {
        cout << "Error: El estado introducido es invalido " << endl;
        return 0; 
    }

    nodo* salida = bfsDDD(raiz);
    imprimirCamino(salida);
}