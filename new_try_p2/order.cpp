#include<iostream>
#include<string>
using namespace std;

void check_order(){
	string order;
	cin >> order;

	if(order == "CREAT")
		creat_point();
	else if(order == "login:")
		login();
	else if(order == "TABLE")
		table_list();
}