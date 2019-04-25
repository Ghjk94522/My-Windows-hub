#include<iostream>
#include"head1.h"
#include<string>
using namespace std;

void check_order(){
    string order_head;
    cin >> order_head;

    if(order == "login:")
    	login();
    else if(order_head == "CREAT")
        creat_point();
    else if(order_head == "DROP")
    	drop_point();
}

void print_sql(){
    cout << "(mysql)==>";
}