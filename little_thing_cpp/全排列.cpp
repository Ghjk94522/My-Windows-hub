#include<iostream>
using namespace std;

//���������е������±�Ϊi��j��Ԫ��
void Swap(int a[], int i,int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

//ʵ�ֵ�m + 1��Ԫ�ص���n + 1��Ԫ��ȫ���е���Ҫ�ݹ麯��
void Pail(int a[], int m,int n)
{
	if (m == n)//�ж�һ��������ϲ����
	{
		for (int i = 0; i <= n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else
	{
		for (int i = m; i <= n; i++)//ͨ���ݹ�ʹmֵ�Լӣ����մﵽn
		{
			Swap(a, m, i);
			Pail(a, m + 1, n);
			Swap(a, m, i);
		}
	}
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	Pail(a,0,4);
	return 0;
}