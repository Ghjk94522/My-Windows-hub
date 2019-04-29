#include<iostream>
#include<string>
using namespace std;

/*
权限文件地址：
"/home/young/progExper/RootHub/" + address + "Root.txt"
内容格式：
owner\t1\t1\t1\t1\t
(只有第一行会出现owner，也就是文件创建者，其余都是四个01数字表示权限)
这里四个权限数字分别对应DROP/INSERT/DELETE/SELETE，用1表示拥有，0表示不拥有

这里地址的读取要依赖于每个用户所对应的TABLE表
表记录文件地址：
"/home/young/progExper/RootHub/" + account + "SQL.txt"
内容格式：
表格名\t表格文件地址\t权限文件地址
*/

extern string account;

void drop_point(){
	string rubbish;
	cin >> rubbish;

	string Tname;
	cin >> Tname;

	string acc_address;
    acc_address = "/home/young/progExper/RootHub/" + account + "SQL.txt";
    const char *p1 = acc_address.data();

    string Tname_local;

    freopen(p1, "r", stdin);
    cin >> Tname_local;
    while(Tname_local != Tname){
    	cin >> rubbish; cin >> rubbish;
    	cin >> Tname_local;
    }

    string Taddress, Troot;
    cin >> Taddress; cin >> Troot;

    fclose(stdin);
    
    const char *p2 = Taddress.data();
    const char *p3 = Troot.data();


	
}