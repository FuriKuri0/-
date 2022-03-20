#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
int main()
{
	
	int a = 0;
	if (createNumber == 0)L = (DuLinkedList*)malloc(sizeof(DuLinkedList));
	createVision(L);
	while (1)
	{
		system("cls");
		printf("双向链表作业\n");
		printf("1.插入节点\n");
		printf("2.修改节点\n");
		printf("3.摧毁链表\n");
		printf("4.退出\n");
		scanf("%d", &a);
		switch (a)
		{
			case 1:
				insertVision(L);
				break;
			case 2:
				alterVision(L);
				break;
			case 3:
				deleteVision(L);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("请输入一个有效数字\n");
				break;
		}
	}
	return 0;
}
void createVision(DuLinkedList *L)
{
	InitList_DuL(L);
	createNumber = 1;
}
void alterVision(DuLinkedList *L)
{
	system("cls");
	int a;
	Status s;
	printf("请输入目标节点的数据\n");
	scanf("%d", &a);
	s = DeleteList_DuL(search_DuL(L, &a), &a);
	if (s == SUCCESS)printf("修改成功");
	else printf("修改失败\n");
	system("pause");
}
void deleteVision(DuLinkedList *L)
{
	if (L != NULL)
	{
		DestroyList_DuL(L);
		L = NULL;
		printf("删除成功\n");
	}
	else printf("链表不存在\n");
	system("pause");
}
void insertVision(DuLinkedList *L)
{
	system("cls");
	int a, c;
	DuLNode *p;
	while (1)
	{
		printf("1.在选择的节点之前插入\n");
		printf("2.在选择的节点之后插入\n");
		scanf("%d", &a);
		if (a == 1 || a == 2)break;
		else printf("输入错误，请重新输入\n");
	}
	printf("请输入要插入节点的位置\n");
	scanf("%d", &c);
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p->data = c;
	p->next = p->prior = NULL;
	if (a == 1)
	{
		int b;
		Status s;
		printf("请输入目标节点的数据\n");
		scanf("%d", &b);
		s = InsertBeforeList_DuL(search_DuL(L, &b), p);
		if (s == SUCCESS)printf("插入成功");
		else printf("插入失败\n");
	}
	if (a == 2)
	{
		int b;
		Status s;
		printf("请输入目标节点的数据\n");
		scanf("%d", &b);
		s = InsertAfterList_DuL(search_DuL(L, &b), p);
		if (s == SUCCESS)printf("插入成功");
		else printf("插入失败\n");
	}
	system("pause");
}
DuLNode* search_DuL(DuLinkedList *L, ElemType *e)
{
	DuLinkedList p;
	p = (DuLinkedList)L;
	while (p)
	{
		if (p->data == *e)break;
		p = p->next;
	}
	if (p == NULL)return p;
	else
		return (p = p->prior);
}
Status InitList_DuL(DuLinkedList *L)
{
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	(*L)->data = 0;
	return SUCCESS;
}
void DestroyList_DuL(DuLinkedList *L)
{
	DuLinkedList p1, p2;
	p1 = (DuLinkedList)L;
	while (p1)
	{
		p2 = p1;
		p1 = p1->next;
		free(p2);
	}
}
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *m;
	if (p == NULL)return ERROR;
	m = p->prior;
	m->next = q;
	q->prior = m;
	q->next = p;
	p->prior = q;
	return SUCCESS;
}
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *m;
	if (p == NULL)return ERROR;
	if (p->next == NULL)
	{
		p->next = q;
		q->prior = p;
	}
	else
	{
		m = p->next;
		m->prior = q;
		q->next = m;
		p->next = q;
		q->prior = p;
	}
	return SUCCESS;
}
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if (p == NULL)return ERROR;
	if (p->next)return ERROR;
	p = p->next;
	p->data = *e;
	return SUCCESS;
}
