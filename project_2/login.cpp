#include<iostream>
#include<string>
#include<vector>
#include"head1.h"
using namespace std;

/*
这里记录一下每个账户文件的格式：
所有账户的账户名和密码统一记录在AP.txt中
格式为账户名\n密码\n账户名\n密码
*/

vector<string> localA, localP;
string account, password;

void login(){
	cin >> account;

	string localPass;

	freopen("/home/ubuntu/yyy/project_2/DataHub/AP.txt", "r", stdin);
	string temp; int i = 1;
	while(cin >> temp){
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

	fclose(stdin);

L0:	cout << "password:";
	char pw[50], ch;
	int j = 0;
	system("stty -echo");
	while((ch = getchar()) != '\r'){
		if(ch == '\b' && i > 0){
			cout << "\b \b"; --i; pw[j] = '\0';
		}
		else{
			pw[j++] = ch;
			cout << "*";
		}
	}
	pw[j] = '\0';

	system("stty echo");
	password = pw;

	if(password == localP[i]){
		print_sql();
		check_order();
	}
	else{
		cout << "The password is wrong, please check and input again./n";
		password.clear();
		print_sql();
		goto L0;
	}
}