#include "GameObject.h"
#include <iostream>

using namespace std;

// ������ ����
GameObject::GameObject(int startX, int startY, int distance) {
    this->x = startX;
    this->y = startY;
    this->distance = distance;
}

// ���� �Ҹ��� ����
GameObject::~GameObject() {}

// ��� �Լ� ����
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


//------�ΰ�--------
Human::Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}

void Human::move() {}

void Human::move(char D) {
    switch (D){
        case 'a': // ��
            x = max(0, x - distance);
            break;
        case 's': // �Ʒ�
            y = min(9, y + distance);
            break;
        case 'd': // ��
            y = max(0, y - distance);
            break;
        case 'f': // ��
            x = min(19, x + distance);
            break;
    }
}

char Human::getShape() {
    return 'H';
}


//------����-----
Monster::Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}

void Monster::move() {
   // ������ �������� �̵�
    int direction = rand() % 4;
    switch (direction) {
        case 0: // ��
            x = max(0, x - distance);
            break;
        case 1: // �Ʒ�
            y = min(9, y + distance);
            break;
        case 2: // ��
            y = max(0, y - distance);
            break;
        case 3: // ��
            x = min(19, x + distance);
            break;
    }
}

char Monster::getShape() {
    return 'M';
}


//------����------
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
