#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Game::Game() : board(10, vector<char>(20, '-')), game_over(false) {
    human = new Human(0, 0, 1);
    monster = new Monster(5, 5, 2);
    food = new Food(9, 9, 1);
}

Game::~Game() {
    delete human;
    delete monster;
    delete food;
}

void Game::set_board() {
    for (auto& row : board) {
        fill(row.begin(), row.end(), '-');
    }

    board[human->getY()][human->getX()] = human->getShape();
    board[monster->getY()][monster->getX()] = monster->getShape();
    board[food->getY()][food->getX()] = food->getShape();
}

void Game::show_board() {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

bool Game::isEnd() {
    return game_over;
}

char Game::input_direct() {
    char direction;
    cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
    cin >> direction;
    return direction;
}

void Game::play_turn() {
    char direction = input_direct();
    human->move(direction); //Human ��ü �̵�
    monster->move(); //Monster ��ü �̵�
    food->move(); //Food ��ü �̵�

    // �浹 �˻�
    if (human->collide(food)) {
        cout << "Human is Winner!!" << endl;
        game_over = true;
    }

    if (human->collide(monster)) {
        cout << "Monster caught a human. Human is loser" << endl;
        game_over = true;
    }

    if (monster->collide(food)) {
        cout << "Monster caught the food. Human is loser" << endl;
        game_over = true;
    }

    set_board();
}