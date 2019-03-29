#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

void set_position(int x, int y) {
	HANDLE win_handle;
	COORD pos = { x, y };
	win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(win_handle, pos);
}

void print_main() {
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" ;
	set_position(30, 5);
	cout << "==== Welcome To KTV System Designed By Young ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "请按提示输入命令序号：\n";
	set_position(30, 11);
	cout << "**   1.管理员界面    **";
	set_position(30, 12);
	cout << "**   2.用户界面      **";
	set_position(30, 13);
	cout << "**   0.退出系统      **";
	set_position(100, 15);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_admin()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "===== Welcome To Interface For Administrator ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "请按提示输入命令序号：\n";
	set_position(30, 13);
	cout << "***   1.查看曲库      ***";
	set_position(30, 14);
	cout << "***   2.歌曲排行      ***";
	set_position(30, 15);
	cout << "***   3.账户管理      ***";
	set_position(30, 16);
	cout << "***   0.返回主界面    ***";
	set_position(30, 18);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_user()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "======== Welcome To Interface For Users ==========";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "请按提示输入命令序号：\n";
	set_position(30, 13);
	cout << "***   1.搜索点歌          ***";
	set_position(30, 14);
	cout << "***   2.查看已点歌曲      ***";
	set_position(30, 15);
	cout << "***   3.改变歌曲顺序      ***";
	set_position(30, 16);
	cout << "***   4.歌曲评分          ***";
	set_position(30, 17);
	cout << "***   0.返回主界面        ***";
	set_position(30, 19);
	cout << "\n\t\t[   ]\b\b\b";
}

bool check_password(string a, string b, string al, string bl)
{

}