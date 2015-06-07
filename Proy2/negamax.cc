#include "othello_cut.h"
#include <iostream>
#include <limits>
#include <time.h>
#include <stdio.h>

using namespace std;
const int MININT = std::numeric_limits<int>::min();
const int MAXINT = std::numeric_limits<int>::max();

unsigned long long nodes_generated = 0;
unsigned long long get_nodes_generate(){return nodes_generated;}
void clean_nodes_generated(){nodes_generated=0;}

unsigned long long nodes_goals = 0;
unsigned long long get_nodes_goals(){return nodes_goals;}
void clean_nodes_goals(){nodes_goals=0;}

int negamax(state_t node,int depth,bool color){
	int val = 0;
	int score;
    bool moved = false;
	state_t child;

	if ((depth == 0) || (node.terminal())){
        nodes_goals+=1;
        if (color == 0){
            return -(node.value());
        }else{
            return (node.value());
        }
	}
	score = MININT;
	for (int i = 4; i < 36;i++){
        if (node.is_free(i)){
    		if (node.outflank(color,i)){
                nodes_generated++;
    			child = node.move(color,i);
    			val = negamax(child,depth,not(color));
                moved = true;
                score = MAX(score,-val);
            }
        }
	}
    if(!moved){
        nodes_generated++;
        val = negamax(node,depth,not(color));
        score = MAX(score,-val);
    }
	return score;
}

int main(int argc, const char **argv) {
    bool player = 0;
    state_t state;
    static int PV2[] = {
        12, 21, 26, 13, 22, 18,  7,  6,  5, 27, 33, 23, 17, 11, 19, 15, 14,
        31, 20, 32, 30, 10, 25, 24, 34, 28, 16,  4, 29, 35, 36,  8,  9 , -1
    };
    //cout << state << endl;
    //cout << "Principal variation:" << endl;
    for(int j=32; j>0;j--){
        state = state_t();
        clean_nodes_generated();
        clean_nodes_goals();
        for( int i = 0; PV[i] != PV2[j]; ++i ) {
            player = i % 2 == 0; // black moves first!
            int pos = PV[i];
            //cout << state;
            //cout << (player ? "Black" : "White")
            //     << " moves at pos = " << pos << (pos == 36 ? " (pass)" : "")
            //     << endl;
            state = state.move(player, pos);
            //cout << "Board after " << i+1 << (i == 0 ? " ply:" : " plies:") << endl;
        }
        //cout << "Estado de entrada al negamaxAB : \n";
        //cout << state;


        int valor = 0;
        clock_t tStart = clock();
        valor =  negamax(state,MAXINT, not(player));
        printf("Tiempo tomado: %.10fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
        cout << " Valor del Juego = " << valor << " " <<  33-j;
        cout << "  Nodos Generados:" << get_nodes_generate();
        cout << "  Nodos Objetivos:" << get_nodes_goals()  <<  endl;
    }

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
