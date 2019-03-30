#include<iostream>
#include<Windows.h>
#include<string>
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
	cout << "***   1.管理曲库      ***";
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

int check_password()
{
	int time = 1;//用于计数
L11:	if (time > 3)
			return 0;
	string account = "NJU_126", password = "NJUYZB";
	string in_account, in_password;
	cout << "\n请输入您的用户名： ";
	cin >> in_account;
	cout << "\n请输入密码: ";
	
	char pw[50], ch;
	int i = 0;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b"; --i; pw[i] = '\0';//经过测试是否修改pw[i]都可以
		}
		else {
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	in_password = pw;

	if (account == in_account && password == in_password)
		return 1;
	else
	{
		cout << "\n\n您输入的密码有误，请检查后重试~ " << "\n您的剩余机会为： " << 3 - time << "次\n";
		time++; goto L11;
	}
}

void print_admin_music_list()
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
	cout << "***   1.单次添加          ***";
	set_position(30, 14);
	cout << "***   2.批量添加          ***";
	set_position(30, 15);
	cout << "***   3.单次删除          ***";
	set_position(30, 16);
	cout << "***   0.返回主界面        ***";
	set_position(30, 19);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_admin_non_order()
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


}