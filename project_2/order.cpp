#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"head1.h"
#include<string>
using namespace std;

void check_order(){
    string order_head;
    cin >> order_head;

    if(order_head == "login:")
    	login();
    else if(order_head == "CREAT")
        creat_point();
    else if(order_head == "DROP");
    	//drop_point();
    else if(order_head == "quit" || order_head == "QUIT")
    	return;
}

void print_sql(){
    cout << "(mysql)==>";
}