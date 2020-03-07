#pragma once
#include <iostream>
using namespace std;
#include "wall.h"
class Food {

public:
	Food(Wall& tempWall);
	void setFood();
	int foodX;
	int foodY;
	Wall& wall;
};