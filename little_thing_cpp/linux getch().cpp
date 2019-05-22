//linux下不包含<conio.h>头文件，现提供一种解决方法

#include<stdio.h>
#include<iostream>
using namespace std;


int main(){
	char c;
	printf("Input a char:");
	system("stty -echo");
	c = getchar();
	system("stty echo");
	printf("You have inputed: %c \n", c);
	return 0;
}