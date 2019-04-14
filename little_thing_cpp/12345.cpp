#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main() {
	string in;
	cin >> in;
	in = "D://" + in + ".txt";
	const char *p = in.data();

	FILE *fp;
	fp = fopen(p, "w+");

	fprintf(fp, "Hello World!\n");
	fclose(fp);

	return 0;
}