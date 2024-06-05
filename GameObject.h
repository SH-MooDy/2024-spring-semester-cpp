#pragma once

class GameObject { // 추상 클래스
protected:
    int distance; // 한 번 이동거리
    int x, y; // 현재 위치
public:
    GameObject(int startX, int startY, int distance); // 생성자 선언
    virtual ~GameObject(); // 가상 소멸자

    virtual void move() = 0; // 이동한 후 새로운 위치로 x,y 변경
    virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴

    int getX(); // 현재 x 위치 반환
    int getY(); // 현재 y 위치 반환
    bool collide(GameObject* p); // 이 객체가 객체 p와 충돌했으면 true 리턴
};

class Human : public GameObject {
public:
    Human(int startX, int startY, int distance);
    void move() override; // move함수를 오버로딩하기 위한 오버라이딩
    void move(char D);
    char getShape() override;
};

class Monster : public GameObject {
public:
    Monster(int startX, int startY, int distance);
    void move() override;
    char getShape() override;
};

class Food : public GameObject {
private:
    int move_count;
public:
    Food(int startX, int startY, int distance);
    void move() override;
    char getShape() override;
};
