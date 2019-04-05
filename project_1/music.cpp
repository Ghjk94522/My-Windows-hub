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
	cout << "请依次输入，歌曲序号，歌曲名，歌手名，歌曲缩写，歌手缩写，后台评分：\n ";
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
	read_list_from_file();
	cout << "以下展示曲库全部歌曲： 依次为序号/曲名/歌手/用户评分/后台评分\n0表示未评分\n";
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
	little_assit();
}

void little_assit()
{
	cout << "输入0返回上一级界面：\n";
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
		case 1: {p->id = temp_l; flag++; break; }
		case 2: {cout << temp_l; p->name_of_song = temp_l; flag++; break; }
		case 3: {p->name_of_singer = temp_l; flag++; break; }
		case 4: {p->short_for_song = temp_l; flag++; break; }
		case 5: {p->short_for_singer = temp_l; flag++; break; }
		case 6: {p->rank_user = temp_l; flag++; break; }
		case 7: {p->rank_admin = temp_l; flag = 1;
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

//字符串转string类
string CharToString(char *contentchar) {
	string tempstr;
	for (int i = 0; contentchar[i] != '\0'; i++)
		tempstr += contentchar[i];
	return tempstr;
}

void remove_music_once()
{
L6:	set_position(30, 3);
	cout << "请输入要移除歌曲的序号： ";

	string id_l; cin >> id_l;
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
	cout << "Failed, the song doesn't exit.Please try again.";
	for (unsigned int i = 0; i < 999999999; i++);
	system("cls");
	goto L6;
}