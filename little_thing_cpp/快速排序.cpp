#include<iostream>
#include "pch.h"
using namespace std;
/*
split函数只是将整个数组分为前后两个部分，但对部分之内的数据不作顺序要求。
所以只需要比较轴心值和下一数据大小即可，由此来看，最优情况是
把整个数组中位数的值选做轴心并置于中央
但很显然难度较大，所以我们只是选择首尾及中央值中的中位值
*/
/*int split(int x[],int first,int last)
{
	int split_point, pivot;//pivot意为“轴”
	pivot = x[first];
	split_point = first;
	for(int unknown = first + 1;unknown <= last;unknown++)
		if (x[unknown] < pivot)
		{
			split_point++;
			//交换x[split_point]和x[unknown]
			int t = x[split_point];
			x[split_point] = x[unknown];
			x[unknown] = t;
		}
	//交换x[firdt]和x[split_point]
	x[first] = x[split_point];
	x[split_point] = pivot;
	return split_point;
}

//有了split函数，将数组分为两部分后，递归排序即可
void sort(int x[], int first, int last)
{
	if (first < last)
	{
		int split_point;
		split_point = split(x, first, last);
		sort(x, first, split_point - 1);
		sort(x, split_point + 1, last);
	}
}*/