#pragma once
#include <vector>
#include <iostream>
#include "GameObject.h"

using namespace std;

class Game {
private:
    vector<vector<char>> board; // 게임 상황을 저장하는 백터 (게임 판)
    Human* human;
    Monster* monster;
    Food* food;
    bool game_over;
public:
    Game(); 
    ~Game();
    void set_board(); // 게임 판을 초기화하는 함수
    void show_board(); // 게임 판을 보여주는 함수
    bool isEnd(); // 게임이 끝났는지 확인하는 함수
    char input_direct(); // 방향 입력을 받아오는 함수
    void play_turn(); // 턴을 진행시키는 함수
};
