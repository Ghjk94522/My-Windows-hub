#include<iostream>
#include"declare_1.h"
#include"declare_2.h"
using namespace std;

void music_choose()
{
L1:	print_user_choose_music();

	int flag = -1;
	while (flag < 0 || flag >= 4) {
		cin >> flag;

		switch (flag) {
		case 1: system("cls"); //view_list();//�鿴����
			break;
		case 2: system("cls"); //singer_choose();//���ݸ����Ѹ�
			break;
		case 3: system("cls"); //song_choose();//���ݸ����Ѹ�
			break;
		case 0: system("cls"); main_interface();//����������
			break;
		default:
			goto L1;//��ֹ����Ƿ����룬��ǿ³����
		}
	}
}