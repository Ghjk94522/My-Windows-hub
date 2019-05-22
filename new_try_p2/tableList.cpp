#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

extern string account;

void table_list(){
	string rubbish;
	cin >> rubbish;

	if(rubbish != "LIST"){
		cout << "WRONG ORDER!!!\n";
		print_sql();
		check_order();
	}
	vector<string> tableName(10);


	string acc_address = "/home/ubuntu/yyy/project_2/RootHub/" + account + "SQL.txt";
	const char *p = acc_address.data();

	
}