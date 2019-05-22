#include<iostream>
#include<string>
#include<vector>
using namespace std;



vector<string> diviStr(string s){
	vector<string> result;
	string temp;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] != ' ')
			temp += s[i];
		else{
			result.push_back(temp);
			temp.clear();
		}
	}
	result.push_back(temp);
	return result;
}

int main(){
	string s = "I am superman and I love you.";
	vector<string> a;
	a = diviStr(s);
	for(vector<string>:: iterator t = a.begin(); t != a.end(); t++)
		cout << *t << " ";
	return 0;
}