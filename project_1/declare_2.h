#include<string>
using namespace std;

void print_main();//������������ʾ
void print_admin();//����Ա����������ʾ
void print_user();//�û�����������ʾ

void set_position(int x, int y);//�������

void print_admin_non_order();//������ʱ��������ʾ

int check_password();//����Ա�����¼������֤
void print_admin_music_list();//�����޸�������ʾ

//�������
void add_music_once();//�������
void remove_music_once();//����ɾ��
void add_music_list();//�б�ʽ���
void show_list_music();//չʾ����
void read_list_from_file();//���ļ��ж�ȡ��Ϣ������
void write_list_to_file();//���뵽�ļ�
void little_assit();//�������������ܲ��ܽ������������
string CharToString(char *contentchar);




//ѡ��ϵͳ
void print_user_choose_music();