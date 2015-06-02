#include "othello_cut.h"
#include <iostream>
#include <limits>

using namespace std;
const int MININT = std::numeric_limits<int>::min();

int negamax(state_t node,int depth,int color){
	int val = 0;
	int score;
	state_t child;

	if ((depth == 0) || (node.terminal())){
		 cout << "Terminar el juego : \n";
		 cout << "Node : \n";
		 cout << node << endl;
		return color*(node.value());
	}

	score = MININT;

	for (int i = 4; i < 36;i++){
		if (node.outflank(color,i)){
			// cout << "Node : \n";
			// cout << node << endl;
			// cout << "Node move : \n";
			// cout << node.move(color,i) << endl;
			// cout << "Depth : " << depth << endl;
			child = node.move(color,i);
			val = negamax(child,depth-1,-color);
		}else{
			cout << "PASEEE";
			val = negamax(node,depth,-color);
		}
		score = MAX(score,-val);
	}

	return score;
}

int main(int argc, const char **argv) {
    state_t state;
    cout << state << endl;
    cout << "Principal variation:" << endl;
    for( int i = 0; PV[i] != 35; ++i ) {
        bool player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        cout << state;
        cout << (player ? "Black" : "White")
             << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
             << endl;
        state = state.move(player, pos);
        cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
    }
    cout << state;
    // cout << "Value of the game = " << state.value() << endl;
    // cout << "#bits per state = " << sizeof(state) * 8 << endl;

    int valor = 0;
    valor = negamax(state,4,1);
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
