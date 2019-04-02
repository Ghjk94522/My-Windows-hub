#include<iostream>
#include<string>
#include<conio.h>
#include"declare_1.h"
#include"declare_2.h"
using namespace std;

void admin_music_list()
{
L1:	print_admin_music_list();

	int flag = -1;
	while (flag < 0 || flag >= 4) {
		cin >> flag;

		switch (flag) {
		case 1: system("cls");// add_music_once();//单次添加
			break;
		case 2: system("cls");// add_music_list();//列表添加
			break;
		case 3: system("cls");// remove_music_once();//单次删除
			break;
		case 0:  system("cls"); main_interface();//返回主界面
			break;
		default:
			goto L1;//防止恶意非法输入，增强鲁棒性
		}
	}
}

void music_rank()
{
	print_admin_non_order();


}

string admin_account(string a)
{
L0:	set_position(30, 3);
	cout << "请输入原始密码： ";

	string b, c, d;
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
	b = pw;
	if (a == b)
	{
L1:		set_position(30, 10);
		cout << "请输入新的密码： ";
		cin >> c;
		set_position(30, 13);
		cout << "请确认密码： ";
		cin >> d;

		if (c == d)
			return c;
		else
		{
			system("cls");
			cout << "两次输入密码不一致，请重试！ ";
			goto L1;
		}
	}
	else
	{
		system("cls");
		cout << "请检查密码是否正确！";
		for (unsigned int i = 0; i < 999999999; i++);
		for (unsigned int i = 0; i < 999999999; i++);
		for (unsigned int i = 0; i < 999999999; i++);
		for (unsigned int i = 0; i < 999999999; i++);
		for (unsigned int i = 0; i < 999999999; i++);
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");
		goto L0;
	}
}