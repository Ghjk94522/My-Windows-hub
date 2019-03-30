//事实上，读取任意键盘输入只需要include一个头文件即可
//需要注意的是，要用getch读取两次，才能判断
#include<conio.h>
int ch;
while ((ch = _getch()) != 0x1B)//判断输入esc退出
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