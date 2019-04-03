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
		case 1: system("cls"); //view_list();//查看曲库
			break;
		case 2: system("cls"); //singer_choose();//根据歌手搜歌
			break;
		case 3: system("cls"); //song_choose();//根据歌名搜歌
			break;
		case 0: system("cls"); main_interface();//返回主界面
			break;
		default:
			goto L1;//防止恶意非法输入，增强鲁棒性
		}
	}
}