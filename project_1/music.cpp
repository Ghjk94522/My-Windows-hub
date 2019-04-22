#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include"declare_2.h"
#include"declare_1.h"
using namespace std;

struct Song {
	int id;
	string name_of_song;
	string name_of_singer;
	string short_for_song;
	string short_for_singer;
	int rank_user;
	int rank_admin;

	Song *next;
	Song *last;
};
Song *head = NULL;

void add_music_once()
{
	read_list_from_file();
	Song *p;
	if (head == NULL)
	{
		p = new Song;
		head = p;
		p->last = NULL;
		p->next = NULL;
	}
	else
	{
		for (p = head; p->next != NULL; p = p->next);
		Song *q = new Song;
		p->next = q; q->last = p; q->next = NULL; p = q;

	}
	set_position(30, 3);
	cout << "���������룬������ţ�����������������������д��������д����̨���֣�\n ";
	cin >> p->id;
	cin >> p->name_of_song;
	cin >> p->name_of_singer;
	cin >> p->short_for_song;
	cin >> p->short_for_singer;
	p->rank_user = 0;
	cin >> p->rank_admin;

	write_list_to_file();

	show_list_music();
}

void add_music_list()
{

}

void show_list_music()
{
	read_list_from_file();
	cout << "����չʾ����ȫ�������� ����Ϊ���/����/����/�û�����/��̨����\n0��ʾδ����\n\n";
	if (head == NULL)
	{
		cout << "Error!The list is empty!";
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");		
		admin_music_list();
	}
	for (Song *p = head; p != NULL; p = p->next)
		cout << p->id << " " << p->name_of_song << " " << p->name_of_singer << " " << p->rank_user << " " << p->rank_admin << "\n";
	little_assit();
}

void little_assit()
{
	cout << "\n����0������һ�����棺\n";
L5:	int i = -1;
	cin >> i;
	if (0 == i) {
		system("cls");
		admin_music_list();
	}
	else
	{
		cout << "Error!Input again:\n";
		goto L5;
	}
}

void read_list_from_file()
{
	FILE *fp;
	fp = fopen("output.txt", "r");
	Song *p = head;
	if (head == NULL)
	{
		p = new Song;
		p->last = NULL;
		p->next = NULL;
		head = p;
	}

	int flag = 1;
	while (1) {
		char temp_2[20];
		fscanf(fp, "%s", temp_2);
		if (feof(fp))
			break;

		string temp_l;
		temp_l = CharToString(temp_2);

		switch (flag) {
		case 1: {p->id = CharToInt(temp_2); flag++; break; }
		case 2: {p->name_of_song = temp_l; flag++; break; }
		case 3: {p->name_of_singer = temp_l; flag++; break; }
		case 4: {p->short_for_song = temp_l; flag++; break; }
		case 5: {p->short_for_singer = temp_l; flag++; break; }
		case 6: {p->rank_user = CharToInt(temp_2); flag++; break; }
		case 7: {p->rank_admin = CharToInt(temp_2); flag = 1;
			if (p->next == NULL)
			{
				Song *q = new Song;
				p->next = q; q->last = p; q->next = NULL; p = q;
			}
			break; }
		}
	}
	fclose(fp);
}

//right
void write_list_to_file()
{
	freopen("output.txt", "w", stdout);

	Song *p = head;
	if (p == NULL)
		cout << " ";
	else
		for (; p != NULL; p = p->next)
		{
			cout << p->id << " " << p->name_of_song << " " << p->name_of_singer << " " 
				<< p->short_for_song << " "<< p->short_for_singer << " " 
				<< p->rank_user << " " << p->rank_admin << endl;
		}

	fclose(stdout);
}

//�ַ���תstring��
string CharToString(char *contentchar) {
	string tempstr;
	for (int i = 0; contentchar[i] != '\0'; i++)
		tempstr += contentchar[i];
	return tempstr;
}

void remove_music_once()
{
L6:	set_position(30, 3);
	cout << "������Ҫ�Ƴ���������ţ� ";

	int id_l; cin >> id_l;
	if (head == NULL)
	{
		cout << "Error! The list is empty!";
		goto L6;
	}
	for (Song *p = head; p != NULL; p = p->next)
	{
		if (p->id != id_l)
			continue;
		else
		{
			Song *q = p->last;
			q->next = p->next;
			p->next->last = q;
			delete p; 
			cout << "Remove successfully!\n Waiting to continue......";
			for (unsigned int i = 0; i < 999999999; i++);
			system("cls");
			admin_music_list();
		}
	}
	cout << "Failed, the song doesn't exist. Please try again.";
	for (unsigned int i = 0; i < 999999999; i++);
	system("cls");
	goto L6;
}

void sort_aud()
{
	Song *p = head;
	if (p == NULL)
	{
		cout << "Error, the list is empty! ";
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");
		main_interface();
	}
	int t = 0;
	for (Song *q = head; q != NULL; q = q->next)t++;
	vector<string> a(t); vector<int> b(t); vector<int> c(t);

	int i = 0;
	for (; p != NULL; p = p->next) {
		a[i] = a[i] + p->name_of_song + p->name_of_singer;
		b[i] = p->id;
		c[i] = p->rank_user;
		i++;
	}

	for (int i = 0; i < t;i++)
	{
		int max = c[i]; int temp_pm = i;
		for (int j = i+1;j < t;j++)
		{
			if (c[j] > max)
			{
				temp_pm = j;
				max = c[j];
			}
		}
		if (max != c[i])
		{
			a[i].swap(a[temp_pm]);
			swap(b[i], b[temp_pm]);
			swap(c[i], c[temp_pm]);
		}
	}

	for (int i = 0; i < 10; i++)
		cout << b[i] << " " << a[i] << " " << c[i] << endl;
}

void sort_adm()
{
	Song *p = head;
	if (p == NULL)
	{
		cout << "Error, the list is empty! ";
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");
		main_interface();
	}
	int t = 0;
	for (Song *q = head; q != NULL; q = q->next)t++;
	vector<string> a(t); vector<int> b(t); vector<int> c(t);

	int i = 0;
	for (; p != NULL; p = p->next) {
		a[i] = a[i] + p->name_of_song + p->name_of_singer;
		b[i] = p->id;
		c[i] = p->rank_admin;
		i++;
	}

	for (int i = 0; i < t; i++)
	{
		int max = c[i]; int temp_pm = i;
		for (int j = i + 1; j < t; j++)
		{
			if (c[j] > max)
			{
				temp_pm = j;
				max = c[j];
			}
		}
		if (max != c[i])
		{
			a[i].swap(a[temp_pm]);
			swap(b[i], b[temp_pm]);
			swap(c[i], c[temp_pm]);
		}
	}
	for (int i = 0; i < 10; i++)
		cout << b[i] << " " << a[i] << " " << c[i] << endl;
}

void show_list_music_u()
{
	read_list_from_file();
	cout << "����չʾ����ȫ�������� ����Ϊ���/����/����/�û�����\n0��ʾδ����\n";
	if (head == NULL)
	{
		cout << "Error!The list is empty!";
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");
		admin_music_list();
	}
	for (Song *p = head; p != NULL; p = p->next)
		cout << p->id << " " << p->name_of_song << " " << p->name_of_singer << " " << p->rank_user << "\n";
	cout << endl;
	little_assit();
}

void singer_choose() {
	cout << "�����������д��ע����ܳ��ֶ��׸��������������ѡ�� \n��ʾ������Ϊ�˿�����\n";
	string in_singer;
	cin >> in_singer;
	int flag = -1;
	for (Song *p = head; p != NULL; p = p->next)
		if (p->short_for_singer == in_singer)
		{
			cout << "\n" << p->id << " " << p->name_of_song << " " << p->name_of_singer << " " << p->rank_user << endl;
			flag = 1;
		}
	if (flag == -1)
	{
		cout << "û�в��ҵ��ø��֣�����ϵ����Ա��Ӹ���~\n";
		music_choose();
	}
	cout << "��������ѡ������ţ�\n";
	int choice; cin >> choice;
}

int CharToInt(char b[]) {
	int t = strlen(b);
	int *a = new int[t];

	for (int i = 0; i < t; i++)
		a[i] = b[i] - '0';
	int temp = 0; int j = t - 1;
	for (int i = 0; i < t; i++)
		temp += a[i] * pow(10, j--);
	return temp;
}