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
		case 1: system("cls");// add_music_once();//�������
			break;
		case 2: system("cls");// add_music_list();//�б����
			break;
		case 3: system("cls");// remove_music_once();//����ɾ��
			break;
		case 0:  system("cls"); main_interface();//����������
			break;
		default:
			goto L1;//��ֹ����Ƿ����룬��ǿ³����
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
	cout << "������ԭʼ���룺 ";

	string b, c, d;
	char pw[50], ch;
	int i = 0;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b"; --i; pw[i] = '\0';//���������Ƿ��޸�pw[i]������
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
		cout << "�������µ����룺 ";
		cin >> c;
		set_position(30, 13);
		cout << "��ȷ�����룺 ";
		cin >> d;

		if (c == d)
			return c;
		else
		{
			system("cls");
			cout << "�����������벻һ�£������ԣ� ";
			goto L1;
		}
	}
	else
	{
		system("cls");
		cout << "���������Ƿ���ȷ��";
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