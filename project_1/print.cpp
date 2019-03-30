#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
using namespace std;

void set_position(int x, int y) {
	HANDLE win_handle;
	COORD pos = { x, y };
	win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(win_handle, pos);
}

void print_main() {
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" ;
	set_position(30, 5);
	cout << "==== Welcome To KTV System Designed By Young ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "�밴��ʾ����������ţ�\n";
	set_position(30, 11);
	cout << "**   1.����Ա����    **";
	set_position(30, 12);
	cout << "**   2.�û�����      **";
	set_position(30, 13);
	cout << "**   0.�˳�ϵͳ      **";
	set_position(100, 15);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_admin()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "===== Welcome To Interface For Administrator ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "�밴��ʾ����������ţ�\n";
	set_position(30, 13);
	cout << "***   1.��������      ***";
	set_position(30, 14);
	cout << "***   2.��������      ***";
	set_position(30, 15);
	cout << "***   3.�˻�����      ***";
	set_position(30, 16);
	cout << "***   0.����������    ***";
	set_position(30, 18);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_user()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "======== Welcome To Interface For Users ==========";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "�밴��ʾ����������ţ�\n";
	set_position(30, 13);
	cout << "***   1.�������          ***";
	set_position(30, 14);
	cout << "***   2.�鿴�ѵ����      ***";
	set_position(30, 15);
	cout << "***   3.�ı����˳��      ***";
	set_position(30, 16);
	cout << "***   4.��������          ***";
	set_position(30, 17);
	cout << "***   0.����������        ***";
	set_position(30, 19);
	cout << "\n\t\t[   ]\b\b\b";
}

int check_password()
{
	int time = 1;//���ڼ���
L11:	if (time > 3)
			return 0;
	string account = "NJU_126", password = "NJUYZB";
	string in_account, in_password;
	cout << "\n�����������û����� ";
	cin >> in_account;
	cout << "\n����������: ";
	
	char pw[50], ch;
	int i = 0;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b"; --i; pw[i] = '\0';//���������Ƿ��޸�pw[i]������
		}
		else {
			pw[i++] = ch;
			cout << "*";
		}
	}
	pw[i] = '\0';
	in_password = pw;

	if (account == in_account && password == in_password)
		return 1;
	else
	{
		cout << "\n\n������������������������~ " << "\n����ʣ�����Ϊ�� " << 3 - time << "��\n";
		time++; goto L11;
	}
}

void print_admin_music_list()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "===== Welcome To Interface For Administrator ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);
	cout << "�밴��ʾ����������ţ�\n";
	set_position(30, 13);
	cout << "***   1.�������          ***";
	set_position(30, 14);
	cout << "***   2.�������          ***";
	set_position(30, 15);
	cout << "***   3.����ɾ��          ***";
	set_position(30, 16);
	cout << "***   0.����������        ***";
	set_position(30, 19);
	cout << "\n\t\t[   ]\b\b\b";
}

void print_admin_non_order()
{
	set_position(30, 3);
	cout << "===================================================";
	set_position(30, 4);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 5);
	cout << "===== Welcome To Interface For Administrator ======";
	set_position(30, 6);
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	set_position(30, 7);
	cout << "===================================================";
	set_position(30, 10);


}