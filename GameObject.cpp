#include "GameObject.h"
#include <iostream>

using namespace std;

// 생성자 정의
GameObject::GameObject(int startX, int startY, int distance) {
    this->x = startX;
    this->y = startY;
    this->distance = distance;
}

// 가상 소멸자 정의
GameObject::~GameObject() {}

// 멤버 함수 정의
int GameObject::getX() {
    return x;
}

int GameObject::getY() {
    return y;
}

bool GameObject::collide(GameObject* p) {
    if (this->x == p->getX() && this->y == p->getY())
        return true;
    else
        return false;
}


//------인간--------
Human::Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}

void Human::move() {}

void Human::move(char D) {
    switch (D){
        case 'a': // 좌
            x = max(0, x - distance);
            break;
        case 's': // 아래
            y = min(9, y + distance);
            break;
        case 'd': // 위
            y = max(0, y - distance);
            break;
        case 'f': // 우
            x = min(19, x + distance);
            break;
    }
}

char Human::getShape() {
    return 'H';
}


//------몬스터-----
Monster::Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}

void Monster::move() {
   // 랜덤한 방향으로 이동
    int direction = rand() % 4;
    switch (direction) {
        case 0: // 좌
            x = max(0, x - distance);
            break;
        case 1: // 아래
            y = min(9, y + distance);
            break;
        case 2: // 위
            y = max(0, y - distance);
            break;
        case 3: // 우
            x = min(19, x + distance);
            break;
    }
}

char Monster::getShape() {
    return 'M';
}


//------음식------
Food::Food(int startX, int startY, int distance) : GameObject(startX, startY, distance), move_count(0){}

void Food::move() {
    move_count++;
    if (move_count >= 5) {
        move_count = 0;
    }
    if(move_count == 2 || move_count == 4){
        int direction = rand() % 4;
        switch (direction) {
        case 0:
            x = max(0, x - distance);
            break;
        case 1:
            y = min(9, y + distance);
            break;
        case 2:
            y = max(0, y - distance);
            break;
        case 3:
            x = min(19, x + distance);
            break;
        }
    }
}

char Food::getShape() {
    return '@';
}
