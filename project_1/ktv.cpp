#define _CRT_SECURE_NO_WARNINGS
#include"declare_1.h"
#include"declare_2.h"
#include<iostream>
#include<string>
using namespace std;


string account = "NJU_126", password = "NJUYZB";

void admin_interface() {
	//��Ҫ�Ƚ���������֤,�����
	int temp = check_password();
	system("cls");
	if (0 == temp) {
		set_position(30, 5);
		cout << "���Ļ���ľ��ˣ��Ѿ��˳�ϵͳ����30������ԡ�\n\n\n";
		return;
	}

L2:	print_admin();
	int flag = -1;
	while (flag < 0 || flag >= 4) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); admin_music_list();//�鿴����
			break;
		case 2: system("cls"); music_rank();//��������
			break;
		case 3: {
			system("cls");
			password = admin_account(password);//�˻�����
			system("cls");cout << "�ɹ���";
			for (unsigned int i = 0; i < 999999999; i++);
			system("cls");
			main_interface();
			break; }
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
		case 1: system("cls"); music_choose();//��������ҳ�沢���
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