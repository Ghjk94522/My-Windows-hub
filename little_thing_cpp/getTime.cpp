#include<iostream>
#include<ctime>
using namespace std;

int main(){
	time_t nowTime;
	nowTime = time(NULL);
	tm* tTm = localtime(&nowTime);
	cout << "Local time is: " << asctime(tTm);
	return 0;
}