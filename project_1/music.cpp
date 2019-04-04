#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"declare_2.h"
#include"declare_1.h"
using namespace std;

struct Song {
	string id;
	string name_of_song;
	string name_of_singer;
	string short_for_song;
	string short_for_singer;
	string rank_user;
	string rank_admin;

	Song *next;
	Song *last;
};
Song *head = NULL;

void add_music_once()
{
	//read_list_from_file();
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
	cout << "���������룬������ţ�����������������������д��������д����̨���֣� ";
	cin >> p->id;
	cin >> p->name_of_song;
	cin >> p->name_of_singer;
	cin >> p->short_for_song;
	cin >> p->short_for_singer;
	p->rank_user = "0";
	cin >> p->rank_admin;

	write_list_to_file();

	show_list_music();
}

void add_music_list()
{

}

void show_list_music()
{
	//read_list_from_file();
	cout << "����չʾ����ȫ�������� ����Ϊ���/����/����/�û�����/��̨����\n0��ʾδ����\n";
	if (head == NULL)
	{
		cout << "Error!The list is empty!";
		for (unsigned int i = 0; i < 999999999; i++);
		system("cls");		
		admin_music_list();
	}
	for (Song *p = head; p != NULL; p = p->next)
		cout << p->id << " " << p->name_of_song << " " << p->name_of_singer << " " << p->rank_user << " " << p->rank_admin << "\n";
	cout << endl;
	cout << "����0������һ�����棺\n";
L5:	int i = -1;
	cin >> i;
	if (0 == i)
		admin_music_list();
	else
	{
		cout << "Error!Input again:\n";
		goto L5;
	}
}


//something wrong
void read_list_from_file()
{
	freopen("output.txt", "r", stdin);
	
	Song *p = head;
	string temp_l; int flag = 1;
	cin >> temp_l;
	while (temp_l != "")
	{
		switch (flag) {
		case 1:p->id = temp_l; flag++; break;
		case 2:p->name_of_song = temp_l; flag++; break;
		case 3:p->name_of_singer = temp_l; flag++; break;
		case 4:p->short_for_song = temp_l; flag++; break;
		case 5:p->short_for_singer = temp_l; flag++; break;
		case 6:p->rank_user = temp_l; flag++; break;
		case 7:p->rank_admin = temp_l; flag = 1;
			if (p->next == NULL)
			{
				Song *q = new Song;
				p->next = q; q->last = p; q->next = NULL; p = q;
			}
			break;
		}
		cin >> temp_l;
	}
	fclose(stdin);
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