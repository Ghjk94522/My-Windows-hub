#include<iostream>
#include<string>
#include<vector>
using namespace std;

extern string account;

void table_list(){
	string rubbish;
	cin >> rubbish;

	string acc_address = "/home/ubuntu/yyy/project_2/RootHub/" + account + "SQL.txt";
	const char *p = acc_address.data();

	freopen(p, "r", stdin);
	cin >>

}