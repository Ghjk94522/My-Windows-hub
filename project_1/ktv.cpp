#define _CRT_SECURE_NO_WARNINGS
#include"declare_1.h"
#include"declare_2.h"
#include<iostream>
#include<string>
using namespace std;

string account = "NJU_123", password = "NJUYZB";


void admin_interface() {
L2:	print_admin();
	//需要先进行密码验证,待填充
	int time = 1;
	if (time <= 3)
	{

	}
	else {
		cout << "请检查您的用户名与密码是否匹配，不要暴力破解密码~\n";
		return;
	}

	int flag = -1;
	while (flag < 0 || flag >= 4) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); //admin_music_list();//查看曲库
			break;
		case 2: system("cls"); //music_rank();//歌曲排行
			break;
		case 3: system("cls"); //admin_account();//账户管理
			break;
		case 0:  system("cls"); main_interface();//返回主界面
			break;
		default:
			goto L2;//防止恶意非法输入，增强鲁棒性
		}
	}
}

void user_interface() {
L3:	print_user();

	int flag = -1;
	while (flag < 0 || flag >= 5) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); //music_choose();//进入搜索页面并点歌
			break;
		case 2: system("cls"); //music_check();//查看已点歌曲
			break;
		case 3: system("cls"); //music_change();//改变歌曲顺序
			break;
		case 4: system("cls"); //music_assess();//歌曲评分
			break;
		case 0: system("cls"); main_interface();//返回主界面
			break;
		default:
			goto L3;//防止恶意非法输入，增强鲁棒性
		}
	}
}

void main_interface() {
L1:	print_main(); 

	int flag = -1;
	while (flag >= 3 || flag < 0) {
	    cin >> flag;

		switch (flag) {
		case 1: system("cls"); admin_interface();//调用管理员界面，需要先进行密码验证
			break;
		case 2: system("cls"); user_interface();//调用用户界面
			break;
		case 0: return;//结束程序
			break;
		default: {
			system("cls");
			goto L1;//防止恶意非法输入，增强鲁棒性
		}
		}
	}
}

int main()
{
	main_interface();
	return 0;
}