#include<iostream>
#include<cstring>
using namespace std;

struct Node {
	int num;
	Node *next;
	Node *last;
};

Node *head = NULL, *lastl = NULL;

//表头插入
void insert_at_beginning(int x)
{
	if (head == NULL)
	{
		Node *p = new Node;
		head = lastl = p;
		p->num = x;
		p->last = NULL;
		p->next = NULL;
	}
	else
	{
		Node *p = new Node;
		head->last = p;
		p->next = head;
		head = p;
		p->num = x;
		p->last = NULL;
	}
}

//表尾插入
void insert_at_ending(int x)
{
	if (lastl == NULL)
	{
		Node *p = new Node;
		head = lastl = p;
		p->num = x;
		p->next = NULL;
		p->last = NULL;
	}
	else
	{
		Node *p = new Node;
		p->last = lastl;
		lastl->next = p;
		lastl = p;
		p->next = NULL;
		p->num = x;
	}
}

//查找后插入
void insert_after(int x, int y)
{
	for (Node *p = head; p != NULL; p = p->next)
	{
		if (p->num == x)
		{
			Node *q = new Node;
			p->next->last = q;
			q->next = p->next;
			q->last = p;
			p->next = q;
			q->num = y;
			break;
		}
	}
}

//查找后删除
void delete_node(int x)
{
	for (Node *p = head; p != NULL; p = p->next)
	{
		if(p->num == x)
		{
			Node *q = p->last;
			q->next = p->next;
			p->next->last = q;
			delete p; break;
		}
	}
}

//顺序打印前n个数
void print(int n)
{
	Node *p = head;
	if (-1 == n)
	{
		for (; p->next != NULL; p = p->next)
			cout << p->num << " ";
		cout << p->num << "\n";
	}
	else {
		for (int count = 1; count < n; count++)
		{
			if (p->next != NULL)
			{
				cout << p->num << " ";
				p = p->next;
			}
		}
		cout << p->num << "\n";
	}
}

//逆序输出n个数
void reverse_print(Node *node,int n)
{
	Node *p; int flag = 1;
	if (-1 == n)
	{
		p = lastl;
		for (; p->last != NULL; p = p->last)
			cout << p->num << " ";
		cout << p->num << "\n";
	}
	else if(1 != n)
	{
		p = node;
		for (int count = 1; count < n; count++)
		{
			if (p->next != NULL)
			{
				p = p->next; flag++;
			}
			else
				break;
		}
		if (flag < n)
			n = flag;
		cout << p->num << " ";
		reverse_print(node, n - 1);
	}
	else if (1 == n)
	{
		p = node;
		cout << p->num << "\n";
		return;
	}
}



int main()
{
	char a[50] = { '\0' };
	cin >> a;
	while (strcmp(a,"#") != 0)
	{
		int flag = 0;
		if (strcmp("insert_at_beginning",a) == 0)
			flag = 1;
		else if (0 == strcmp("insert_at_ending",a))
			flag = 2;
		else if (0 == strcmp("insert_after",a))
			flag = 3;
		else if (0 == strcmp("delete_node",a))
			flag = 4;
		else if (0 == strcmp("print",a))
			flag = 5;
		else if (0 == strcmp("reverse_print",a))
			flag = 6;
		else
		{
			cerr << "Input error!";
			exit(-1);
		}
		
		switch (flag)
		{
		case 1: {
			int x; cin >> x;
			insert_at_beginning(x);
		}break;
		case 2: {
			int x; cin >> x;
			insert_at_ending(x);
		}break;
		case 3: {
			int x, y; cin >> x >> y;
			insert_after(x, y);
		}break;
		case 4: {
			int x; cin >> x;
			delete_node(x);
		}break;
		case 5: {
			int x; cin >> x;
			print(x);
		}break;
		case 6: {
			int x; cin >> x;
			reverse_print(head, x);
		}break;
		}

		memset(a, 0, sizeof(a));
		cin >> a;
	}

	return 0;
}