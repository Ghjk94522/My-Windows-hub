#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;


/*int main() {
	HANDLE hout;
	COORD coord;
	coord.X = 30; coord.Y = 3;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	cout << "===================================================" << endl;

	int ch;
	while ((ch = _getch()) != 0x1B)
	{
		switch (ch) {
		case 0xE0:
			switch(ch = _getch())
		{
		case 75:cout << "left \n"; break;
		case 72:cout << "up \n"; break;
		case 77:cout << "right \n"; break;
		case 80:cout << "down \n"; break;
		default:break;
		}
		default:break;
		}
	}
	return 0;
}*/