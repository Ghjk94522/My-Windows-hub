#include<iostream>
#include "pch.h"
using namespace std;
/*
split����ֻ�ǽ����������Ϊǰ���������֣����Բ���֮�ڵ����ݲ���˳��Ҫ��
����ֻ��Ҫ�Ƚ�����ֵ����һ���ݴ�С���ɣ��ɴ����������������
������������λ����ֵѡ�����Ĳ���������
������Ȼ�ѶȽϴ���������ֻ��ѡ����β������ֵ�е���λֵ
*/
/*int split(int x[],int first,int last)
{
	int split_point, pivot;//pivot��Ϊ���ᡱ
	pivot = x[first];
	split_point = first;
	for(int unknown = first + 1;unknown <= last;unknown++)
		if (x[unknown] < pivot)
		{
			split_point++;
			//����x[split_point]��x[unknown]
			int t = x[split_point];
			x[split_point] = x[unknown];
			x[unknown] = t;
		}
	//����x[firdt]��x[split_point]
	x[first] = x[split_point];
	x[split_point] = pivot;
	return split_point;
}

//����split�������������Ϊ�����ֺ󣬵ݹ����򼴿�
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