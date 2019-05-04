#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
账户文件格式：
统一记录在AP.txt中，这一txt文件放在RootHub中
内容为：账户名\n密码\n
*/

vector<string> localA, localP;//用来记录AP.txt中的账户和密码
string account, password;//用来记录输入的账户和密码

void login(){
	cin >> account;

	string lPassw;//用来记录对应的账户密码

	freopen("/home/ubuntu/yyy/project_2/DataHub/AP.txt", "r", stdin);
	string temp; 
	//const char *p = temp.data();

	int t = 1;
	while(cin >> temp){
		if(1 == t){
			localA.push_back(temp);
			temp.clear();
			t = 0;
		}
		else{
			localP.push_back(temp);
			temp.clear();
			t = 1;
		}
	}
	//这里循环输入账号和密码
	fclose(stdin);

	int i = 0;
	char pw[50], ch;
L0:	cout << "password:";
	system("stty -echo");
	while((ch = getchar()) != '\r'){
		if(ch == '\b' && i > 0){
			cout << "\b \b";--i;
		}
		else{
			pw[i++] = ch;
			cout << '*';
		}
	}
	pw[i] = '\0';
	system("stty echo");
	password = pw;//密文输入密码

	int j = 0;
	for(vector<string>::iterator t = localA.begin(); t != localA.end(); t++){
		if(account == *t)
			break;
		else
			j++;
	}//判断账户位置

	if(password == localP[j]){
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