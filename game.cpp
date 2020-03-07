#include <iostream>
using namespace std;
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;             
	pos.Y = y;            
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
	srand((unsigned int)time(NULL));
	bool isDead = false;
	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();
	Food food(wall);

	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();

	/*wall.setWall(5, 4, '=');
	wall.setWall(5, 5, '=');
	wall.setWall(5, 6, '@');*/

	/*snake.move('w');
	snake.move('w');
	snake.move('a');*/
	
	gotoxy(hOut, 0, Wall::ROW);
	cout << "Score: " << snake.getScore() << endl;


	while (!isDead) {
		char key = _getch();
		if (preKey==NULL&&key == snake.LEFT) {
			continue;
		}

		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)) {
					key = preKey;
				} else {
					preKey = key;
				}
				


				if (snake.move(key) == true) {
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);
					cout << "Score: " << snake.getScore() << endl;
					Sleep(snake.getSleepTime());
				} else {
					isDead = true;
					break;
				}
			} else {
				 key=preKey;
			}
			
		} while (!_kbhit());
		
	}
	

	/*cout << wall.getWall(0, 0) << endl;
	cout << wall.getWall(5, 4) << endl;

	cout << wall.getWall(5, 6) << endl;
	cout << wall.getWall(1, 1) << endl;*/
	system("pause");
	return EXIT_SUCCESS;
}