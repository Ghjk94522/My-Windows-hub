#include<iostream>
#include<string>
#include"head1.h"
using namespace std;

vector<string> localA, localP;

void login(){
	string account, password;
	cin >> account;

	string localPass;

	FILE *fp = fopen("/home/young/progExper/DataHub/AP.txt", "r");
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

L0:	cout << "password:";
	char pw[50], ch;
	int j = 0;
	while((ch = getch()) != '\r'){
		if(ch == '\b' && i > 0){
			cout << "\b \b"; --i; pw[j] = '\0';
		}
		else{
			pw[j++] = ch;
			cout << "*";
		}
	}
	pw[j] = '\0';

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