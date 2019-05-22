#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m; int t = n*m;
	int *p = new int[t];//boxNum
	int *p_up = new int[t];
	for (int i = 0; i < t; i++)
		cin >> p[i];

	for (int i = 0; i < t; i++){
		p_up[i] = 0;
	}
	//upSight
	for (int i = 0; i < t;i++)
	if (p[i] == 0)p_up[i] = 1;
	//frontSight
	int *p_front = new int[m];
	for (int j = 0; j < m; j++){
		int max = 0;
		for (int i = 0; i < n; i++){
			if (p[i*m + j] > max)
				max = p[i*m + j];
		}
		p_front[j] = max;
	}
	//leftSight
	int *p_left = new int[n];
	for (int j = 0; j < n; j++){
		int max = 0;
		for (int i = 0; i < m;i++)
		if (p[j*m + i] > max)
			max = p[j*m + i];
		p_left[j] = max;
	}


	int leftMax = 0;
	for (int i = 0; i < n; i++)
	if (p_left[i] > leftMax)leftMax = p_left[i];

	int frontMax = 0;
	for (int i = 0; i < m; i++)
	if (p_front[i] > frontMax)frontMax = p_front[i];

	int front11 = frontMax * m;
	int left11 = leftMax * n;
	char *upSight = new char[t];
	char *leftSight = new char[left11];
	char *frontSight = new char[front11];

	//up
	for (int i = 0; i < t; i++)
	{
		if (p_up[i] == 1)upSight[i] = '.';
		else upSight[i] = '#';
	}
	//left
	int tt = 0;
	for (int j = 0; j < n; j++){
		int temp = p_left[tt++];
		for (int i = leftMax - 1; i >= 0; i--){
			if (temp > 0){
				leftSight[i*n + j] = '#'; temp--;
			}
			else leftSight[i*n + j] = '.';
		}
	}
	

	//front
	int ttt = 0;
		for (int j = 0; j < m;j++){
			int temp = p_front[ttt++];
		for (int i = frontMax - 1; i >= 0; i--){
			if (temp > 0){
				frontSight[i * m + j] = '#'; temp--;
			}
			else frontSight[i * m + j] = '.';
		}
	}

	for (int i = 0; i < t; i++)
	{
		cout << upSight[i];
		if ((i+1) % (m) == 0)cout << endl;
	}
	cout << endl;
	for (int i = 0; i < front11; i++)
	{
		cout << frontSight[i];
		if ((i+1) % (m) == 0)cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= left11; i++)
	{
		cout << leftSight[i];
		if ((i+1) % (n) == 0 && i != left11)cout << endl;
	}
	return 0;
}

