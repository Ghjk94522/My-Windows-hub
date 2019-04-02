#pragma once
#include<string>
using namespace std;
void admin_interface();//管理员界面
void admin_music_list();//查看曲库
void music_rank();//歌曲排行
string admin_account(string a);//账户管理

void user_interface();//用户界面
void music_choose();//进入搜索页面并点歌
void music_check();//查看已点歌曲
void music_change();//改变歌曲顺序
void music_assess();//歌曲评分

void main_interface();//主界面