#include "Game.h"
#include <iostream>

using namespace std;

void start_game(Game& G) { 
    G.set_board(); // 게임보드 초기화
    while (!G.isEnd()){
        G.show_board();
        G.play_turn();
    }
}

int main() {
    Game G;
    start_game(G);
    return 0;
}
