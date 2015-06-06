#include "othello_cut.h"
#include <iostream>
#include <limits>

using namespace std;
const int MININT = std::numeric_limits<int>::min();
const int MAXINT = std::numeric_limits<int>::max();

bool test(state_t node,int depth,int value,bool color){ // sign 1 == >. sign 0 == <.
    state_t child;
    bool moved = false;

    if ((depth == 0) || (node.terminal())){
        return node.value() > value;
    }

    for (int i = 4; i < 36;i++){
        if (node.is_free(i)){
            if (node.outflank(color,i)){
                child = node.move(color,i);
                moved = true;
                if ((color == 1) && (test(child,depth-1,value,not(color)))){
                    return true;
                }
                if ((color == 0) && (!(test(child,depth-1,value,not(color))))){
                    return false;
                }
            }
        }
        if ((!moved) && (i == 35)){
            return test(node,depth-1,value,not(color));
        }
    }
    if (color == 1)
        return false;
    else
        return true;  
}

int scout(state_t node,int depth,bool color){
    int score;
    state_t child;
    bool firstChild = true;
    bool moved = false;

    if ((depth == 0) || (node.terminal())){
        return node.value();
    }

    score = 0;

    for (int i = 4; i < 36;i++){
        if (node.is_free(i)){
            if (node.outflank(color,i)){
                child = node.move(color,i);
                if (firstChild){
                    score = scout(child,depth-1,not(color));
                    firstChild = false;
                    moved = true;
                }
                else{
                    if ((color == 1) && (test(child,depth-1,score,not(color)))){
                        score = scout(child,depth-1,not(color));
                        moved = true;
                    }
                    if ((color == 0) && (!test(child,depth-1,score,not(color)))){
                        score = scout(child,depth-1,not(color));
                        moved = true;
                    }
                }
            }
        }
        if ((!moved) && (i == 35)){
            score = scout(node,depth-1,not(color));
        }
    }
    return score;
}




int main(int argc, const char **argv) {
    bool player = 0;
    state_t state;
    cout << state << endl;
    cout << "Principal variation:" << endl;
    for( int i = 0; PV[i] != 15 ; ++i ) {
        player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        cout << state;
        cout << (player ? "Black" : "White")
             << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
             << endl;
        state = state.move(player, pos);
        cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
    }
    cout << "Estado de entrada al negamax : \n";
    cout << state;
    // cout << "Value of the game = " << state.value() << endl;
    // cout << "#bits per state = " << sizeof(state) * 8 << endl;

    int valor = 0;
    valor = scout(state,MAXINT, not(player));
    cout << "Value of the game = " << valor << endl;

    if( argc > 1 ) {
        int n = atoi(argv[1]);
        cout << endl << "Apply " << n << " random movements at empty board:";
        state = state_t();
        for( int i = 0; i < n; ++i ) {
            bool player = i % 2 == 0; // black moves first
            int pos = state.get_random_move(player);
            state = state.move(player, pos);
            cout << " " << pos;
        }
        cout << endl << state;
    }

    return 0;
}