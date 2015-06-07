#include "othello_cut.h"
#include <iostream>
#include <limits>

using namespace std;
const int MININT = std::numeric_limits<int>::min();
const int MAXINT = std::numeric_limits<int>::max();

int negascout(state_t node,int depth, int alpha, int beta,bool color){
    int score;
    state_t child;
    bool firstChild = true;
    bool moved = false;

    if ((depth == 0) || (node.terminal())){
        if (color==0) {
            return -(node.value());
        }
        return node.value();
    }

    score = 0;

    for (int i = 4; i < 36;i++){
        if (node.is_free(i)){
            if (node.outflank(color,i)){
                child = node.move(color,i);
                if (firstChild){
                    score = -negascout(child,depth-1,-beta,-alpha,not(color));
                    firstChild = false;
                    moved = true;
                }
                else{
                    score = -negascout(child,depth-1,-alpha - 1,-alpha,not(color));
                    moved = true;
                    if ((alpha < score) && (score < beta)){
                        score = -negascout(child,depth-1,-beta,-score,not(color));
                    }
                }

                alpha = MAX(alpha, score);
                if (alpha >= beta){
                    break;
                }
            }
        }
        if (!(moved) && (i==35)){
            if (firstChild){
                score = -negascout(node,depth-1,-beta,-alpha,not(color));
            }
            else{
                score = -negascout(node,depth-1,-alpha - 1,-alpha,not(color));
                if ((alpha < score) && (score < beta)){
                    score = -negascout(node,depth-1,-beta,-score,not(color));
                }
            }

            alpha = MAX(alpha, score);
            if (alpha >= beta){
                break;
            }
        }
    }
    return alpha;
}




int main(int argc, const char **argv) {
    bool player = 0;
    state_t state;
    cout << state << endl;
    cout << "Principal variation:" << endl;
    for( int i = 0; PV[i] != 25; ++i ) {
        player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        //cout << state;
        //cout << (player ? "Black" : "White")
        //     << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
        //     << endl;
        state = state.move(player, pos);
        //cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
    }
    cout << "Estado de entrada al negascout : \n";
    cout << state;
    // cout << "Value of the game = " << state.value() << endl;
    // cout << "#bits per state = " << sizeof(state) * 8 << endl;

    int valor = 0;
    valor = negascout(state,MAXINT,MININT,MAXINT,not(player));
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
