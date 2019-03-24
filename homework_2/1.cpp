#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//树的结构实现
struct TNode
{
	int num;
	int count;
	TNode *next[10];
	TNode *last;
};
TNode *root;

//插入根节点
void insert_at_root(int x)
{
	if (root == NULL)
	{
		root = new TNode;
		root->num = x;
		root->last = NULL;
		for (int i = 0; i < 10; i++)
			root->next[i] = NULL;
		root->count = 0;
	}
	else
	{
		TNode *p = new TNode;
		p->num = x;
		p->next[0] = root;
		p->count = 1;
		p->last = NULL;
		root->last = p;
		root = p;
	}
}

//插入叶子节点
void insert_after(TNode *node, int x, int y)
{
	TNode *p = node;
	if (p == NULL)
		return;
	else
	{
		if (p->num == x)
		{
			TNode *q = new TNode;
			q->num = y;
			q->last = p;
			p->next[p->count] = q;
			p->count++;
			q->count = 0;
			for (int i = 0; i < 10; i++)
				q->next[i] = NULL;
			return;
		}
		else
		{
			for (int i = 0; i < p->count; i++)
				insert_after(p->next[i], x, y);
		}
	}
}

//删除叶子节点
void delete_node(TNode *node, int x)
{
	TNode *p = node;
	if (p == NULL)
		return;
	else
	{
		if (p->num == x && p->next[0] == NULL)
		{
			p->last->count--;
			p->last->next[p->last->count] = NULL;
			delete p; 
			p = NULL;
			return;
		}
		else
		{
			for (int i = 0; i < p->count; i++)
				delete_node(p->next[i], x);
		}
	}
}

//输出树的节点
void print(TNode *node, int n)
{
	TNode *p = node;
	if (p == NULL || 0 == n)
		return;
	else
	{
		if (-1 == n)
		{
			cout << p->num << " ";
			for (int i = 0; i < p->count; i++)
				print(p->next[i], -1);
		}
		else
		{
			cout << p->num << " ";
			for (int i = 0; i < p->count; i++)
				print(p->next[i], n - 1);
		}
		cout << endl;
	}
}

int main()
{
	freopen("in.txt", "a+", stdin);
	freopen("out.txt", "w+", stdout);

	char a[50] = { '\0' };
	cin >> a;
	while (strcmp(a, "#") != 0)
	{
		int flag = 0;
		if (strcmp("insert_at_root", a) == 0)
			flag = 1;
		else if (0 == strcmp("insert_after", a))
			flag = 2;
		else if (0 == strcmp("delete_node", a))
			flag = 3;
		else if (0 == strcmp("print", a))
			flag = 4;
		else
		{
			cerr << "Input error!";
			exit(-1);
		}

		switch (flag)
		{
		case 1: {
			int x; cin >> x;
			insert_at_root(x);
		}break;
		case 2: {
			int x, y; cin >> x >> y;
			insert_after(root, x, y);
		}break;
		case 3: {
			int x; cin >> x;
			delete_node(root, x);
		}break;
		case 4: {
			int x; cin >> x;
			print(root, x);
		}break;
		}

		memset(a, 0, sizeof(a));
		cin >> a;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}