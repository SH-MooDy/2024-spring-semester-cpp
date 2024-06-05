#pragma once
#include <vector>
#include <iostream>
#include "GameObject.h"

using namespace std;

class Game {
private:
    vector<vector<char>> board; // ���� ��Ȳ�� �����ϴ� ���� (���� ��)
    Human* human;
    Monster* monster;
    Food* food;
    bool game_over;
public:
    Game(); 
    ~Game();
    void set_board(); // ���� ���� �ʱ�ȭ�ϴ� �Լ�
    void show_board(); // ���� ���� �����ִ� �Լ�
    bool isEnd(); // ������ �������� Ȯ���ϴ� �Լ�
    char input_direct(); // ���� �Է��� �޾ƿ��� �Լ�
    void play_turn(); // ���� �����Ű�� �Լ�
};
