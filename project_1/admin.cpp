#include<iostream>
#include"declare_1.h"
#include"declare_2.h"
using namespace std;

void admin_music_list()
{
L1:	print_admin_music_list();

	int flag = -1;
	while (flag < 0 || flag >= 3) {
		cin >> flag;

		switch (flag) {
		case 1: system("cls");// add_music_once();//�������
			break;
		case 2: system("cls");// add_music_list();//�б����
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