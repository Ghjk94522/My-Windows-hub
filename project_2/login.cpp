#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>
#include<string>
<<<<<<< HEAD
#include"head1.h"
using namespace std;

=======
#include<vector>
#include"head1.h"
using namespace std;

/*
这里记录一下每个账户文件的格式：
所有账户的账户名和密码统一记录在AP.txt中
格式为账户名\n密码\n账户名\n密码
*/
>>>>>>> dev

vector<string> localA, localP;
string account, password;

void login(){
	cin >> account;

	string localPass;

	FILE *fp = fopen("AP.txt", "r");
	//freopen("/home/ubuntu/yyy/project_2/DataHub/AP.txt", "r", stdin);
	string temp; int i = 1;

	const char *ppp = temp.data();
	while(fscanf(fp, "%s", ppp) != EOF){
		if(1 == i){
			localA.push_back(temp);
			temp.clear();
			i = 0;
		}
		else{
			localP.push_back(temp);
			temp.clear();
			i = 1;
		}
	}

	i = 1;
	for(vector<string>::iterator t = localA.begin(); t != localA.end(); t++){
		if(account == *t)
			break;
		else
			i++;
	}

<<<<<<< HEAD
	cout << "password:";
L0:	char pw[50], ch;
=======
	fclose(fp);

L0:	cout << "password:";
	char pw[50], ch;
>>>>>>> dev
	int j = 0;
	//system("stty -echo");
	while((ch = _getch()) != '\r'){
		if(ch == '\b' && i > 0){
			cout << "\b \b"; --i; pw[j] = '\0';
		}
		else{
			pw[j++] = ch;
			cout << "*";
		}
	}
	pw[j] = '\0';

	//system("stty echo");
	password = pw;

	if(password == localP[i]){
		print_sql();
		check_order();
	}
	else{
<<<<<<< HEAD
		cout << "Pass word is wrong, please check and input again.";
		for(int i = 1; i < 9999999; i++);
		system("cls");
		cout << "password:";
		password.clear();
		goto L0;
	}
		

=======
		cout << "The password is wrong, please check and input again./n";
		password.clear();
		print_sql();
		goto L0;
	}
>>>>>>> dev
}