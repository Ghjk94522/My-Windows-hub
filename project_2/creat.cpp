#include<iostream>
#include<stdio.h>
#include"head1.h"
#include<vector>
using namespace std;

vector<string> column;

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
    string address; cin >> address; //address -= ".txt";
    address = "/home/young/progExper/DataHub/" + address;

    const char *p = address.data();

    FILE *fp;
    fp = fopen(p, "a");

    fprintf(fp, t_name.c_str());
    fprintf(fp, "\n\n");
    fprintf(fp, "id\t");
    for(vector<string>:: iterator t = column.begin(); t != column.end(); t++){
        fprintf(fp, t->c_str());
        fprintf(fp, "\t");
    }

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
