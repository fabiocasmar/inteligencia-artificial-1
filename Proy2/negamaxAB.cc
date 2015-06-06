#include "othello_cut.h"
#include <iostream>
#include <limits>

using namespace std;
const int MININT = std::numeric_limits<int>::min();
const int MAXINT = std::numeric_limits<int>::max();

int negamaxAB(state_t node,int depth, int alpha, int beta,bool color){
	int val = 0;
	int score;
    bool moved = false;
	state_t child;

	if ((depth == 0) || (node.terminal())){
        if (color == 0){
            color = -1;
        }
		return color*(node.value());
	}

	score = MININT;

	for (int i = 4; i < 36;i++){
        if (node.is_free(i)){
    		if (node.outflank(color,i)){
    			child = node.move(color,i);
    			val = negamaxAB(child,depth-1,-beta,-alpha,not(color));
                moved = true;
                score = MAX(score,-val);
                alpha = MAX(alpha,-val);
                if (alpha >= beta) break;
            }
        }
        if ((!moved) && (i == 35)){
            cout << "Pasé" << endl;
            val = negamaxAB(node,depth-1,-beta,-alpha,not(color));
            score = MAX(score,-val);
            alpha = MAX(alpha,-val);
            if (alpha >= beta) break;
        }
	}

	return score;
}

int main(int argc, const char **argv) {
    bool player = 0;
    state_t state;
    cout << state << endl;
    //cout << "Principal variation:" << endl;
    for( int i = 0; PV[i] != 36 ; ++i ) {
        player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        //cout << state;
        //cout << (player ? "Black" : "White")
        //     << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
        //     << endl;
        state = state.move(player, pos);
        //cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
    }
    cout << "Estado de entrada al negamaxAB : \n";
    cout << state;

    int valor = 0;
    valor = negamaxAB(state, MAXINT, MININT, MAXINT, not(player));
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
