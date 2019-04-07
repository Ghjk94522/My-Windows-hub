#include<string>
using namespace std;

void print_main();//主界面命令提示
void print_admin();//管理员界面命令提示
void print_user();//用户界面命令提示

void set_position(int x, int y);//句柄设置

void print_admin_non_order();//无命令时，界面显示

int check_password();//管理员界面登录密码验证
void print_admin_music_list();//曲库修改命令提示

//曲库管理
void add_music_once();//单次添加
void remove_music_once();//单次删除
void add_music_list();//列表式添加
void show_list_music();//展示曲库
void read_list_from_file();//从文件中读取信息到链表
void write_list_to_file();//输入到文件
void little_assit();//辅助函数试试能不能解决缓冲区问题
string CharToString(char *contentchar);

//评分系统
void sort_aud();
void sort_adm();//给链表排序


//选歌系统
void print_user_choose_music();
void show_list_music_u();//用户查看曲库
void singer_choose();//根据歌手选歌
int CharToInt(char b[]);//类型转换