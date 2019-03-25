#include<iostream>
using namespace std;

bool isok(int a[])
{
	if (a[0] != a[1] && a[0] != a[2] &&
		a[0] != a[3] && a[0] != a[4] &&
		a[1] != a[2] && a[1] != a[3] &&
		a[1] != a[4] && a[2] != a[3] &&
		a[2] != a[4] && a[3] != a[4])
		return 1;
	return 0;
}

int Max(int a[])
{
	int max = a[0];
	for (int i = 1; i < 5;i++)
	if (a[i] > max)
		max = a[i];
	return max;
}

int Min(int a[])
{
	int min = 10086;
	for (int i = 0; i < 5;i++)
	if (a[i] != 0 && a[i] < min)
		min = a[i];
	return min;
}

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	bool zero = 0;
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == 0)
			zero = 1;
	}
	double sum = 0;
	if (zero == 0)
	{
		for (int i = 0; i < 5; i++)
			sum += a[i];
		double aver = sum / 5;
		if (Max(a) - Min(a) == 4)
		{
			if (aver == a[0] || aver == a[1] || aver == a[2] || aver == a[3] || aver == a[4])
			{
				if (isok(a))
					cout << "yes";
				else
					cout << "no";
			}
		}
		else
			cout << "no";
	}
	if (zero != 0)
	{
		int numof0 = 0;
		for (int i = 0; i < 5; i++)
		if (a[i] == 0)
			numof0++;
		int t = Max(a) - Min(a);
		if (numof0 == 5 || numof0 == 4)
			cout << "yes";
		else if (numof0 == 1)
		{
			if (isok(a) && t == 4 || t == 3)
				cout << "yes";
			else
				cout << "no";
		}
		else if (numof0 == 2)
		{
			int j = 0; int temp[3];
			for (int i = 0; i < 5; i++)
			{
				if (a[i] != 0)
				{
					temp[j] = a[i];
					j++;
				}
			}
			if (temp[0] != temp[1] && temp[0] != temp[2] && temp[1] != temp[2])
			{
				if (t == 2 || t == 3 || t == 4)
					cout << "yes";
				else
					cout << "no";
			}
			else
				cout << "no";
		}
		else if (numof0 == 3)
		{
			int j = 0; int temp[2];
			for (int i = 0; i < 5; i++)
			{
				if (a[i] != 0)
				{
					temp[j] = a[i];
					j++;
				}
			}
			if (temp[0] != temp[1])
			{
				if (t == 1 || t == 2 || t == 3 || t == 4)
					cout << "yes";
				else
					cout << "no";
			}
			else
				cout << "no";
		}
		else
			cout << "no";
	}

	return 0;
}