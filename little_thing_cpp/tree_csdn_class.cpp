#pragma once
#ifndef Tree_H
#define Tree_H
const int Max = 20;
 
struct TNode {
	char data;
	TNode *firstchild, *rightsib;
};
 
class Tree {
public:
	Tree();
	~Tree() { Release(root); }
	void PreOrder() { PreOrder(root); }  //前序遍历
	void PostOrder() { PostOrder(root); }  //后序遍历
//private:
	TNode *root;
	void Release(TNode *bt);
	void PreOrder(TNode *bt);
	void PostOrder(TNode *bt);
};
 
#endif //


#include<iostream>
#include "Tree.h"
using namespace std;
 
Tree::Tree() {
	TNode *Q[Max] = { NULL };
	int front = -1, rear = -1;
	char ch1 = '#', ch2 = '#';
	TNode *p, *q;
	cout << "Please input root node!: " << endl;
	cin >> ch1;
	p = new TNode;
	p->data = ch1;
	p->firstchild = p->rightsib = NULL;
	root = p;
	Q[++rear] = p;
	cout << "Please input new node:"<< endl;
	cin >> ch2;
	cout << "Please input its parent node:" << endl;
	cin >> ch1;
	//fflush(stdin);
	//ch1 = getchar(); getchar(); ch2 = getchar();
	while (ch1 != '#' || ch2 != '#') {
		p = new TNode;
		p->data = ch2;
		p->firstchild = p->rightsib = NULL;
		Q[++rear] = p;
		while (front != rear) {
			q = Q[front + 1];
			if (q->data != ch1) {
				front++;
			}
			else {
				if (q->firstchild == NULL) {
					q->firstchild = p;
				}
				else {
					//q = q->firstchild;
					while (q->rightsib != NULL) {
						q = q->rightsib;
					}
					q->rightsib = p;
				}
				break;
			}
		}
		cout << "Please input new node:" << endl;
		cin >> ch2;
		cout << "Please input its parent node:" << endl;
		cin >> ch1;
	}
	cout << "Tree has been created!" << endl;
}
 
void Tree::Release(TNode *bt) {
	if (bt == NULL) return;
	else {
		Release(bt->firstchild);
		Release(bt->rightsib);
		delete bt;
	}
}
 
void Tree::PreOrder(TNode *bt) {
	if (bt == NULL) {
		return;
	}
	else {
		cout << bt->data << endl;
		PreOrder(bt->firstchild);
		PreOrder(bt->rightsib);
	}
}
 
void Tree::PostOrder(TNode *bt) {
	if (bt == NULL) return;
	else {
		PostOrder(bt->firstchild);
		PostOrder(bt->rightsib);
		cout << bt->data << endl;
	}
}
