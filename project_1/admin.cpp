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
		case 1: system("cls");// add_music_once();//单次添加
			break;
		case 2: system("cls");// add_music_list();//列表添加
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