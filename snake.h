#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

class Snake {
public:
	Snake(Wall&tempWall, Food&food);
	enum { UP = 'w', DOWN = 's',LEFT = 'a', RIGHT = 'd' };
	struct Point {
		int x;
		int y;

		Point* next;
	};

	void initSnake();
	void destroyPoint();
	void addPoint(int x, int y);
	bool move(char key);
	int getSleepTime();
	int countList();
	int getScore();


	void deletePoint();
	Point* pHead;
	Wall& wall;
	Food& food;
	bool isRool;
};