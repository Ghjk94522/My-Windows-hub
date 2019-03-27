#include<iostream>
using namespace std;

/*
-----------------------------------------------------
|---------------------Title-------------------------|
|---------------------------------------------------|
|-------------用函数实现str相关的库函数-------------|
|---------------------------------------------------|
|----------Writed By Zhibin Yang--------------------|
|---------------------------------------------------|
|----------All Rights Reserved----------------------|
|---------------------------------------------------|
|----------Latest Edited At 1/10/19-----------------|
-----------------------------------------------------
*/

//First: strlen
int strlen_126(const char a[])
{
	int len = 0;
	for (int i = 0; a[i] != '\0'; i++)
		len++;
	return len;
}

//Second:strcmp
bool strcmp_126(const char a[], const char b[])
{
	int len1 = strlen_126(a), len2 = strlen_126(b);
	if (len1 != len2)
		return 0;
	else
		for(int i = 0;i < len1;i++)
			if (a[i] != b[i])
				return 0;
	return 1;
}

//Third:strcpy
void strcpy_126(char a[], const char b[])//(destination, resource)
{
	int len2 = strlen_126(a);
	int len = strlen_126(b);
	if (len > len2)
	{
		cout << "目标地址空间小于资源空间，请重试！\n";
		return;
	}
	if (a[0] != '\0')
	{
		for (int i = 0; i < len2; i++)
			a[i] = 0;
	}
	for (int i = 0; i < len; i++)
		a[i] = b[i];
}

//Forth:strcat_126
void strcat_126(char a[], const char b[])//(destination, resource)
{
	int len2 = strlen_126(a);
	int len = strlen_126(b);
	int temp = len2;
	for (int i = 0; i < len; i++)
	{
		a[temp] = b[i];
		temp++;
	}
}
