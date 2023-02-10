
//hello world

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>

#define SIZE3_3 3 
#define SIZE4_4 4

#define ESC 46
#define UP 46
#define DOWN 80
#define ENTER 13
#define RIGHT 77
#define LEFT 75
#define BACKSPACE 8
#define SIZE 4
#define SIZE1 3

#define SIZE(X) (X)? SIZE3_3 : SIZE4_4

/*cout<<"Hello world";*/

using namespace std;
int X, Y;
int arr2[4][4]{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15,0 },
};
void findZero() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr2[i][j] == 0) {
				X = i;
				Y = j;
			}
		}
	}
}
void Print() {
	cout << "\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < 4; i++) {
		cout << setw(50);
		for (int j = 0; j < 4; j++) {

			cout << arr2[i][j] << setw(5);
		}
		cout << endl << endl;
	}
	cout << endl;
}
void TurnUpDown(int a){
	if (a == UP) {
		if (Y != 0) {
			swap(arr2[X][Y], arr2[X][Y + 1]);
			Y++;
		}
	}
	else {
		if (Y != SIZE(1)-1) {
			swap(arr2[X][Y], arr2[X][Y - 1]);
			Y--;
		}
	}
}
void TurnLeftRight(int a){
	if (a == RIGHT) {
		if (X != 0) {
			swap(arr2[X][Y], arr2[X+1][Y]);
			X++;
		}
	}
	else {
		if (X != SIZE(1)-1) {
			swap(arr2[X][Y], arr2[X-1][Y]);
			X--;
		}
	}
}


string menu[6]{
{ "ИГРАТЬ"},
{"ВЫХОД" },
{ "8(3x3)"},
{"15(4x4)" },
{ "РУЧНОЕ РАЗМЕШИВАНИЕ"},
{"АВТОМАТИЧЕСКОЕ РАЗМЕШИВАНИЕ" }
};
int choice = 0;
void Menu(int c = 0) {
	//void (*op[5])() {func1, func2};
	int key = UP;	
	do {
		
		system("cls");
		cout
			<< ((choice == 0)? "<<":"") << menu[c] << ((choice == 0) ? ">>" : "") << endl
			<< ((choice == 1) ? "<<" : "") << menu[c+1] << ((choice == 1) ? ">>" : "") << endl;
		_getch();
		key = _getch();
		if (key == UP) choice--;
		else if (key == ENTER) {
			Menu(choice);
			//op[choice]();
		}
		else choice+=6;
	} while (1);

}



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	/*int key;
	findZero();
	do
	{
		Print();
		_getch();
		key = _getch();
		cout << key << endl;
		switch (key)
		{
		case UP:
		case DOWN:
			TurnUpDown(key);
			break;
		case LEFT:
		case RIGHT:
			TurnLeftRight(key);
			break;
		}
		
	} while (true);*/


	Menu();
}
