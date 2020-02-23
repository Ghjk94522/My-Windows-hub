# AVL树相关算法整理



在AVL树中，有几种调整算法如下：

当不平衡时，需要调整的节点处于一条直线上时，我们需要进行单旋转：



注意我们并没有给出AVL树的定义，因为我习惯使用struct而书上使用的时c++的类声明实现，但是AVL树中包括的除了常规的子树之外，还有bf值，用来确定数的高度差，0为完全平衡，正数表示右子树高，负数表示左子树高



- 左单旋转（用于处理三个节点右偏的情形：

```c++
void RotateL(AVLnode *ptr){
    AVLnode *sub = ptr;
    ptr = sub->right;
    sub->right = ptr->left;
    ptr->left = sub;
    ptr->bf = sub->bf = 0; // bf means the sub of height
}
```

- 右单旋转

```c++
template <class E, class K>
void AVLtree<E, K>::RotateR(AVLnode<E, K> *& ptr){
    AVLnode<E, K> * sub = ptr;
    ptr = sub->left;
    sub->left = ptr->right;
    ptr->right = sub;
    ptr->bf = sub->bf = 0;
}
```



当需要调整的节点形成折线时，我们需要进行双旋转：

- 先左后右双旋转：
  - 对于呈 < 型的不平衡子树来说，我们将右下的节点调整为根节点，将其余两个按大小顺序调整为其子节点

```c++
void RotateLR(AVLnode *ptr){
    AVLnode *subR = ptr, *subL = subR->left;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    if(ptr->bf <= 0)
        subL->bf = 0;
    else
        subL->bf = -1;
    subR->left = ptr->right;
    ptr->right = subR;
    if(ptr->bf == -1)
        subR->bf = 1;
    else 
        subR->bf = 0;
    ptr->bf = 0;
}
```

- 先右后左双旋转：

```c++
template <class E, class K>
void AVLtree<E, K>::RotateRL(AVLnode<E, K> *& ptr){
    AVLnode<E, K> * subl = ptr, *subr = subl->right;
    ptr = subr->left;
    subr->left = ptr->right;
    ptr-right = subr;
    if(ptr->bf >= 0)
        subr->bf = 0;
    else
        subr->bf = 1;
    subl->right = ptr->left;
    ptr->left = subl;
    if(ptr->bf == 1)
        subl->bf = -1;
    else 
        subl->bf = 0;
    ptr->bf = 0;
}
```



- AVL树的插入算法：

  - 首先我们要考虑几种基本情况，以新插入节点的父节点P为分类标准：

    - 若P的平衡因子为0，说明插入节点使原树平衡，不需要进行处理，返回即可

    - 若P的平衡因子的绝对值为1，说明之前P是平衡的，不需要调整，但还需要考察P的父节点直到根节点查看是否存在失衡

    - 若P的平衡因子的绝对值为2，说明这次插入使树失衡了，我们可以进一步分类如下：

      - 当P的bf等于2，说明右子树高，结合其右子女q的bf值处理：
        - 当q的bf为1，执行左单旋转
        - 当q的bf为-1，执行先右后左双旋转
      - 当P的bf等于-2说明左子树高，结合其左子女的bf值处理：
        - 当q的bf为-1，执行右单旋转
        - 当q的bf为1，执行先左后右双旋转

      旋转后以P为根的子树高度降低，无需回溯

```c++
void insertAVLTree(Tree *tree, int value)
{
	Node *node = createAVLNode(value);
	if (tree->root == NULL){
		tree->root = node;
		return;
	}
	Node *n = tree->root;
	while (1){
		n->size++;
		if (value < n->value){
			if (n->left == NULL){
				n->left = node;
				node->parent = n;
				break;
			}
			n = n->left;
		}
		else{
			if (n->right == NULL){
				n->right = node;
				node->parent = n;
				break;
			}
			n = n->right;
		}
	}
	AVLInsertFixup(tree, node);
}

void AVLInsertFixup(Tree *tree, Node *z){
	Node *tmp = z;
	while (z != NULL){
		z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
		if (z->parent != NULL && z->parent->parent != NULL){
			Node *zp = z->parent;
			Node *zpp = zp->parent;
			zp->height = max(getHeight(zp->left), getHeight(zp->right)) + 1;
			zpp->height = max(getHeight(zpp->left), getHeight(zpp->right)) + 1;
			if (getHeight(zpp->left) - getHeight(zpp->right) == -2){
				// 左旋zpp之前确保zp的右树高大于等于左树高
				if (getHeight(zp->left) > getHeight(zp->right)){
					AVLRightRotate(tree, zp);
				}
				AVLLeftRotate(tree, zpp);
			}
			else if (getHeight(zpp->left) - getHeight(zpp->right) == 2){
				// 右旋zpp之前确保zp的左树高大于等于右树高
				if (getHeight(zp->left) < getHeight(zp->right)){
					AVLLeftRotate(tree, zp);
				}
				AVLRightRotate(tree, zpp);
			}
		}
		z = z->parent;
	}
}

int getHeight(Node *node)
{
	if (node == NULL)	return -1;
	return node->height;
}
```



- AVL树的删除算法：

  - 同样我们依然要分类讨论，对于被删除的节点P做分类如下：

    - P有两个子女：搜索P在中序次序下的直接后继q，把q传给P，现在问题转移为删除至多只有一个子节点的情况。

    - P最多只有一个子结点：可以简单的把P的父节点Pr中指向P的指针直接指向q，将以Pr为根的子树高度减一，并向上递归查看修改对路径上各个节点的影响。

      其中分情况讨论比较复杂，我们不在此赘述，直接show the code：

      ```c++
      template <class E, class K>
      bool AVLtree<E, K>::Remove(AVLnode<E, K> *& ptr, K x, E &e1){
          //在以ptr为根的树中删除关键码为x的节点
          AVLnode<E, K> *pr = NULL, *p = ptr, *q, *ppr;
          int d, dd = 0;
          stack<AVLnode<E, K> *> st;
          while(p != NULL){
              if(k == p->data.key)
                  break;
              pr = p;
              st.push(pr);
              if(k < p->data.key)
                  p = p->keft;
             	else
                  p = p->right;
          }
          if(p == NULL)
              return false;
          if(p->left != NULL && p->right != NULL){
              pr = p;
              st.push(pr);
              q = p->left;
              while(q->right != NULL){
                  pr = q;
                  st.push(pr);
                  q = q->right;
              }
              p->data = q->data;
              p = q;
          }
          if(p->left != NULL)
              q = p->left;
          else
              q = p->right;
          if(pr == NULL)
              ptr = q;
          else{
              if(pr->left == p)
                  pr->left = q;
              else
                  pr->right = q;
              while(st.IsEmpty() == false){
                  st.Pop(pr);
                  if(pr->right == q)
                      pr->bf--;
                  else
                      pr->bf++;
                  if(st.IsEmpty() == false){
                      st.Pop(pr);
                      if(pr->right == q)
                          pr->bf--;
                      else
                          pf->bf++;
                      if(st.IsEmpty() == false){
                          st.getTop(ppr);
                          dd = (ppr->left == pr) ？ -1 : 1;
                      }
                      else
                          dd = 0;
                      if()
                  }
              }
          }
      }
      ```

      - 事实上我们只需要考虑几种情况的bf值即可：
      - 如果Pr的平衡因子不为0，且较短的子树又被缩短，那么Pr就不平衡，假设Pr较高子树的根为q，再根据q的平衡因子进行讨论：
        - 假设q的平衡因子为0，对pr执行单旋转
        - 假设q的平衡因子与Pr的同号，那么对Pr执行单旋转，由于此时以q为根的新子树高度发生了变化，所以我们要继续沿路径向上递归考虑是否需要平衡化
        - 假设q的平衡因子与Pr反号，则对Pr执行双旋转，由于此时以q为根的新子树高度发生了变化，所以我们要继续沿路径向上递归考虑是否需要平衡化



