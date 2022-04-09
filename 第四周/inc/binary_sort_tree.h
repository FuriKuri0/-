//
// Created by eke_l on 2021/4/21.
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define n 50

typedef int ElemType;

typedef struct Node {
	ElemType value;
	struct Node *left, *right;
} Node, *NodePtr;

typedef struct BinarySortTree {
	Node* root;
} BinarySortTree, *BinarySortTreePtr;
Status BST_search(NodePtr head, ElemType a, NodePtr temp, NodePtr* p);
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
typedef struct {
	Node a[n];
	int size;//表示栈中含有的元素数量
} stack;
Node pop(stack *p) {
	--(p->size);
	return p->a[p->size];
}
void push(stack *p, Node b) {
	p->a[p->size] = b;//栈顶元素为a[p->size-1]
	++p->size;
}
int empty(stack *p) {
	return p->size == 0;
}
Status numJudge(int *a) {
	scanf("%d", a);
	int judge = getchar();
	while (judge != 10) {
		while (getchar() != '\n');
		printf("请输入有效数字！\n");
		scanf("%d", a);
		judge = getchar();
	}
	return 1;
}
Status BST_init(BinarySortTreePtr* tree) {

	(*tree) = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	(*tree)->root = NULL;
	printf("初始化成功!\n");
	return 1;
}
Status judge(BinarySortTree* tree) {
	if (tree == NULL) {
		printf("树未初始化!\n");
		return 0;
	}
	if (tree->root == NULL) {
		printf("树为空!\n");
		return 0;
	}
	return 1;
}
/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr tree) {
	if (tree == NULL) {
		printf("树未初始化!");
		return 0;
	}
	printf("请输入要插入的值:\n");
	ElemType a;
	numJudge(&a);
	NodePtr p;
	if (tree->root == NULL) {//树未空
		NodePtr temp;
		temp = (NodePtr)malloc(sizeof(Node));
		temp->left = NULL;
		temp->right = NULL;
		temp->value = a;
		tree->root = temp;
		printf("插入成功，该结点为头结点\n");
		return 1;
	}
	if (!BST_search(tree->root, a, NULL, &p)) { //若树无该节点
		NodePtr temp;
		temp = (NodePtr)malloc(sizeof(Node));
		temp->left = NULL;
		temp->right = NULL;
		temp->value = a;
		printf("p的值为 %d \n", p->value);
		if (a < p->value) {
			p->left = temp;
		} else if (a > p->value) {
			p->right = temp;
		}
		printf("插入成功\n");
		return 1;
	} else {
		printf("该树已有该节点!\n");
	}
	return 1;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
NodePtr findParent(NodePtr head, NodePtr child) {
	if (head == NULL) {
		return NULL;
	}
	if (head->left == child || head->right == child) {
		return head;
	}
	NodePtr left = findParent(head->left, child);
	if (left) {
		return left;
	}
	NodePtr right = findParent(head->right, child);
	if (right) {
		return right;
	}
	return NULL;
}
	Status BST_delete(NodePtr * head, ElemType key) {
		NodePtr p;
		NodePtr f = NULL;
		NodePtr q, s;
		if (BST_search(*head, key, NULL, &p)) {
			if (p->left == NULL && p->right != NULL) {
				q = p->right;
				p->value = q->value;
				p->right = q->right;
				p->left = q->left;
				free(q);
			} else if (p->left != NULL && p->right == NULL) {
				q = p->left;
				p->value = q->value;
				p->right = q->right;
				p->left = q->left;
				free(q);
			} else if (p->left != NULL && p->right != NULL) {
				q = p;
				s = p->left;
				while (s->right) { //找左孩子最右孩子
					q = s;
					s = s->right;
				}
				p->value = s->value;
				if (q == p) {
					q->left = s->left;
				} else {
					q->right = s->left;
				}
				free(s);
			} else {

				if (*head == p) {
					(*head) = NULL;
					free(*head);//不知道为什么free掉了会变成0还在;
					printf("删除成功!\n");
					return 1;
				}
				NodePtr parent = findParent(*head, p);
//			printf("parent:%d\n",parent->value);
				if (parent->left == p) {
					parent->left = NULL;
				} else if (parent->right == p) {
					parent->right = NULL;
				}
				free(p);
			}
			printf("删除成功!\n");
		} else {
			return 1;
		}
		return 1;
	}

	/**
	 * BST search
	 * @param BinarySortTreePtr BST
	 * @param ElemType the value to search
	 * @return is exist
	 */
	Status BST_search(NodePtr head, ElemType a, NodePtr temp, NodePtr * p) { //p为指向的最后一个结点
		if (!head) {
			printf("该树无该结点\n");
			*p = temp;
			return 0;
		}
		if (head->value == a) {
			*p = head;
			return 1;
		} else if (head->value < a) {
			return BST_search(head->right, a, head, p);
		}
		return BST_search(head->left, a, head, p);

	}

	/**
	 * BST preorder traversal without recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_preorderI(Node head) {
		printf("先序非递归:\n");
		stack temp;
		push(&temp, head);
		while (!empty(&temp)) {
			head = pop(&temp);
			printf("%d ", head.value);
			if (head.right != NULL) {
				push(&temp, *head.right);
			}
			if (head.left != NULL) {
				push(&temp, *head.left);
			}
		}
		return 1;
	}

	/**
	 * BST preorder traversal with recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_preorderR(NodePtr tree) {
		if (tree == NULL) {
			return 0;
		}
		printf("%d ", tree->value);
		BST_preorderR(tree->left);
		BST_preorderR(tree->right);
		return 1;
	}

	/**
	 * BST inorder traversal without recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_inorderI(Node * head) {
		printf("中序非递归:\n");
//		while(head!=NULL){
//			printf("%d\n",head->value);
//			head=head->left;
//		}
//		printf("111\n");
//
		stack* s1;
		s1 = (stack*)malloc(sizeof(stack));
		s1->size = 0;
		while (head != NULL || !empty(s1)) {
			if (head != NULL) {
				push(s1, *head);
				head = head->left;
			}
			if (head == NULL) {
				Node temp;
				temp = pop(s1);
				head = &temp;
				printf("%d ", head->value);
				head = head->right;
			}
		}
//		if(head==NULL){
//			printf("22222\n");
//		}
		printf("\n");
		return 1;
	}

	/**
	 * BST inorder traversal with recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_inorderR(NodePtr tree) {
		if (tree == NULL) {
			return 0;
		}
		BST_inorderR(tree->left);
		printf("%d ", tree->value);
		BST_inorderR(tree->right);
		return 1;
	}

	/**
	 * BST preorder traversal without recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_postorderI(Node head) {
		printf("后序非递归:\n");
		stack* s1;
		s1 = (stack*)malloc(sizeof(stack));
		stack* s2;
		s2 = (stack*)malloc(sizeof(stack));
		push(s1, head);
		while (!empty(s1)) {
			head = pop(s1);
			push(s2, head);
			if (head.left != NULL) {
				push(s1, *head.left);
			}
			if (head.right != NULL) {
				push(s1, *head.right);
			}
		}
		while (!empty(s2)) {
			printf("%d ", pop(s2).value);
		}
		return 1;
	}

	/**
	 * BST postorder traversal with recursion
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status BST_postorderR(NodePtr tree) {
		if (tree == NULL) {
			return 0;
		}
		BST_postorderR(tree->left);
		BST_postorderR(tree->right);
		printf("%d ", tree->value);
		return 1;
	}
	typedef struct node {
		Node* data;                   //数据域指针
		struct node *next;            //指向当前结点的下一结点
	} LNode;

	typedef struct Lqueue {
		LNode *front;                   //队头
		LNode *rear;                    //队尾
		int length;            //队列长度
	} *LQueue, Lqueue;
	/**
	 * BST level order traversal
	 * @param BinarySortTreePtr BST
	 * @param (*visit) callback
	 * @return is successful
	 */
	Status IsEmptyLQueue(LQueue Q) {
		if (Q->length == 0) {
			return 1;
		} else if (Q->length > 0) {
			return 0;
		} else if (Q->length < 0) {
			printf("错误!\n");
			return 0;
		}
	}
	Status EnLQueue(LQueue Q, LNode * temp) {
		if (Q->length == 0) {
			Q->front = temp;
			Q->rear = temp;
		} else {
			Q->rear->next = temp;
			Q->rear = temp;
		}
		Q->length ++;
		return 1;
	}
	LNode* DeLQueue(LQueue Q) {
		if (Q->length == 0) {
			printf("空了怎么弹出啊\n");
			return 0;
		}
		LNode *temp;
		temp = (LNode*)malloc(sizeof(LNode));
		temp = Q->front;
//	if (Q->front == NULL) {
//		printf("为空NULL\n");
//	} else {
//		printf("不为空，值为:%d\n", Q->front->data->value);
//	}
		if (Q->length == 1) {
			Q->rear = NULL;
		}
		Q->front = Q->front->next;
		Q->length--;
		return temp;
	}
	Status BST_levelOrder(NodePtr head) {
		LQueue L;
		L = (LQueue)malloc(sizeof(Lqueue));
		LNode *p;
		p = (LNode*)malloc(sizeof(LNode));
		p->data = head;
		p->next = NULL;
		L->front = p;
		L->rear = p;
		L->length = 1;
		while (!IsEmptyLQueue(L)) {
			LNode* cur = DeLQueue(L);
			printf("%d ", cur->data->value);
			if (cur->data->left != NULL) {
				LNode *temp;
				temp = (LNode*)malloc(sizeof(LNode));
				temp->data = cur->data->left;
				temp->next = NULL;
				EnLQueue(L, temp);
			}
			if (cur->data->right != NULL) {
				LNode *temp;
				temp = (LNode*)malloc(sizeof(LNode));
				temp->data = cur->data->right;
				temp->next = NULL;
				EnLQueue(L, temp);
			}
		}
		return 1;
	}

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
