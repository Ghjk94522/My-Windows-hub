#include<iostream>
#include<stdio.h>
#include"head1.h"
#include<vector>
using namespace std;

extern string account;

vector<string> column;

/*
这里加一些注释，用全局变量account引入对每个用户数据库的表名和对应文件地址的记录
其中t_name表示表名，acc_address表示地址
顺序也是表名 \t 地址
每次使用creat新的表的时候都要先记录表名和地址的一一对应
*/

void creat_point(){
    string rubbish; cin >> rubbish;
    string t_name; cin >> t_name;

    char temp; string temp_column;
    scanf("%c", &temp);
    scanf("%c", &temp);
    if(temp == '('){
        scanf("%c", &temp);
    
    while(temp != ')'){
        if(temp != ' ' && temp != ',')
            temp_column += temp;
    scanf("%c", &temp);
    
    if(temp == ','){
        column.push_back(temp_column);
        temp_column.clear();
    }
    
    }
    
    cin >> rubbish;
    string address; cin >> address; 
    address = substr(0, address.length() - 4);
    string address_root; address_root = "/home/young/progExper/RootHub/" + address + "Root.txt";
    address = "/home/young/progExper/DataHub/" + address + ".txt";

    const char *p0 = address.data();

    FILE *fp;
    fp = fopen(p0, "a");

    fprintf(fp, t_name.c_str());
    fprintf(fp, "\n\n");
    fprintf(fp, "id\t");
    for(vector<string>:: iterator t = column.begin(); t != column.end(); t++){
        fprintf(fp, t->c_str());
        fprintf(fp, "\t");
    }

    fclose(fp);
    
    string acc_address;
    acc_address = account + "SQL.txt";
    const char *p1 = acc_address.data();
    FILE *fp = fopen(p1, "a");

    fprintf(fp, "\n");
    fprintf(fp, t_name->c_str());
    fprintf(fp, "\t");
    fprintf(fp, address->c_str());

    fclose(fp);

    const char *q = address_root.data();
    FILE *fp = fopen(q, "a");
    fprintf(fp, "owner\t1\t1\t1\t1\t");//这里四个权限数字分别对应DROP/INSERT/DELETE/SELETE，用1表示拥有，0表示不拥有
    fclose(fp);

    

    }

    /*else if(temp == 'F'){
         scanf("%c", &temp); scanf("%c", &temp); scanf("%c", &temp); scanf("%c", &temp);
L1:      string address; cin >> address;
         address = "/home/young/progExper/DataHub/" + address;
         const char *p = address.data();

         FILE *fp = fopen(p, "r");
         if(fp == NULL){
            cout << "The file doesn't exist. Please check your filename and input again.\n\n"
            goto L1;
         }
         else{
            string oneLine; const char *q = oneLine.data();

            getline(q, 65536, '#');
            
         }
    }*/


}
