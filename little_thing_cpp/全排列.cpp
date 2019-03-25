#include<iostream>
using namespace std;

//交换数组中的两个下标为i和j的元素
void Swap(int a[], int i,int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

//实现第m + 1个元素到第n + 1个元素全排列的主要递归函数
void Pail(int a[], int m,int n)
{
	if (m == n)//判断一次排列完毕并输出
	{
		for (int i = 0; i <= n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else
	{
		for (int i = m; i <= n; i++)//通过递归使m值自加，最终达到n
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