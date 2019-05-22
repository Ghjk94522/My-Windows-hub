#include<iostream>
#include<string>
#include<vector>
#include"head.h"

using namespace std;

extern string account;

vector<string> column;

/*
引入login中的全局变量account方便记录文件名
新变量t_name为表格名, address表示表格所在txt的地址
内容为：表名\t地址
每次使用creat都要新建一个文件记录这一结构

每个表格对应一个权限文件，地址为address_root

每个用户对应一个记录文件，地址为acc_address

对权限的具体说明放在下面
*/

void creat_point(){
	string rubbish; cin >> rubbish;//TABLE
	string t_name; cin >> t_name;

	char temp; string temp_column;
	scanf("%c", &temp); scanf("%c", &temp);
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
		}//结束循环的条件是temp读到了）

		cin >> rubbish;//TO
		string address; cin >> address;//address记录的是file，也就是包含.txt的文件名，但是没有绝对地址
		address = address.substr(0, address.length() - 4);//去掉.txt，方便进一步加工

		string address_root;
		address_root = "/home/ubuntu/yyy/project_2/RootHub/" + account + "Root.txt";

		string acc_address = "/home/ubuntu/yyy/project_2/RootHub/" + account + "SQL.txt";

		address = "/home/ubuntu/yyy/project_2/DataHub/" + address + ".txt";

		const char *p0 = acc_address.data();//写入用户拥有的表格记录文件

		//格式为：表格名\t表格文件地址\t表格权限地址
		FILE *fp0 = fopen(p0, "a");
		fprintf(fp0, "\n%s", t_name.c_str());
		fprintf(fp0, "\t%s", address.c_str());
		fprintf(fp0, "\t%s", address_root.c_str());

		fclose(fp0);


		//输入表格聂内容，首行是表格名，之后是id+表头
		const char *p1 = address.data();

		FILE *fp1 = fopen(p1, "a");
		fprintf(fp1, "%s\n\nid\t", t_name.c_str());
		for(vector<string>:: iterator t = column.begin(); t != column.end(); t++){
			fprintf(fp1, "%s\t", t->c_str());
		}
		fclose(fp1);


		//记录用户文件库，格式为：表格名，表格文件地址
		const char *p2 = acc_address.data();
		FILE *fp2 = fopen(p2, "a");
		fprintf(fp2, "\n%s\t%s\towner", t_name.c_str(), address.c_str());
		fclose(fp2);

		//记录权限文件，格式为：用户名\t1\t1\t1\t1
		const char *p3 = address_root.data();
		FILE *fp3 = fopen(p3, "a");
		fprintf(fp3, "\n%s\t1\t1\t1\t1", account.c_str());
		fclose(fp3);

		cout << "Successful!\n";
		print_sql();
		check_order();



	}

	
}