#pragma once

class GameObject { // �߻� Ŭ����
protected:
    int distance; // �� �� �̵��Ÿ�
    int x, y; // ���� ��ġ
public:
    GameObject(int startX, int startY, int distance); // ������ ����
    virtual ~GameObject(); // ���� �Ҹ���

    virtual void move() = 0; // �̵��� �� ���ο� ��ġ�� x,y ����
    virtual char getShape() = 0; // ��ü�� ����� ��Ÿ���� ���� ����

    int getX(); // ���� x ��ġ ��ȯ
    int getY(); // ���� y ��ġ ��ȯ
    bool collide(GameObject* p); // �� ��ü�� ��ü p�� �浹������ true ����
};

class Human : public GameObject {
public:
    Human(int startX, int startY, int distance);
    void move() override; // move�Լ��� �����ε��ϱ� ���� �������̵�
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
