#include "wall.h"

void Wall::initWall(){
	for (int i = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '*';
			} else {
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawWall() {
	for (int i = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			cout << gameArray[i][j]<<" ";
		}
		if (i == 3) {
			cout << "V 1.0";
		}
		if (i == 4) {
			cout << "Date:03/2020";
		}
		if (i == 5) {
			cout << "Created by Ming Lei";
		}
		if (i == 6) {
			cout << "a: left";
		}
		if (i == 7) {
			cout << "d: right";
		}
		if (i == 8) {
			cout << "w: up";
		}
		if (i == 9) {
			cout << "s: down";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c) {
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y) {
	return gameArray[x][y];
}