#include <iostream>
#include <string>

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
            return true;
        }
    } // El else if the abajo es para evitar que movimientos seguidos contrarios pasen.
    else if ((((labelHijo[2] == 'W') and (labelPadre[2] == 'C')) 
                or ((labelHijo[2] == 'C') and (labelPadre[2] == 'W'))
                    or ((labelHijo[2] == '8') and (labelPadre[2] == '8')))
                        and (labelPadre[0] == labelHijo[0])){
            return true;
    }

    return false;
}