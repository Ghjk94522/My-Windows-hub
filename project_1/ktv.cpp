#define _CRT_SECURE_NO_WARNINGS
#include"declare_1.h"
#include"declare_2.h"
#include<iostream>
#include<string>
using namespace std;


void admin_interface() {
	//��Ҫ�Ƚ���������֤,�����
	int temp = check_password();
	system("cls");
	if (0 == temp)
		return;

L2:	print_admin();
	int flag = -1;
	while (flag < 0 || flag >= 4) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); admin_music_list();//�鿴����
			break;
		case 2: system("cls"); music_rank();//��������
			break;
		case 3: system("cls"); //admin_account();//�˻�����
			break;
		case 0:  system("cls"); main_interface();//����������
			break;
		default:
			goto L2;//��ֹ����Ƿ����룬��ǿ³����
		}
	}
}

void user_interface() {
L3:	print_user();

	int flag = -1;
	while (flag < 0 || flag >= 5) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); //music_choose();//��������ҳ�沢���
			break;
		case 2: system("cls"); //music_check();//�鿴�ѵ����
			break;
		case 3: system("cls"); //music_change();//�ı����˳��
			break;
		case 4: system("cls"); //music_assess();//��������
			break;
		case 0: system("cls"); main_interface();//����������
			break;
		default:
			goto L3;//��ֹ����Ƿ����룬��ǿ³����
		}
	}
}

void main_interface() {
L1:	print_main(); 

	int flag = -1;
	while (flag >= 3 || flag < 0) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); admin_interface();//���ù���Ա���棬��Ҫ�Ƚ���������֤
			break;
		case 2: system("cls"); user_interface();//�����û�����
			break;
		case 0: return;//��������
			break;
		default: {
			system("cls");
			goto L1;//��ֹ����Ƿ����룬��ǿ³����
		}
		}
	}
}

int main()
{
	main_interface();
	return 0;
}