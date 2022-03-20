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
		printf("˫��������ҵ\n");
		printf("1.����ڵ�\n");
		printf("2.�޸Ľڵ�\n");
		printf("3.�ݻ�����\n");
		printf("4.�˳�\n");
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
				printf("������һ����Ч����\n");
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
	printf("������Ŀ��ڵ������\n");
	scanf("%d", &a);
	s = DeleteList_DuL(search_DuL(L, &a), &a);
	if (s == SUCCESS)printf("�޸ĳɹ�");
	else printf("�޸�ʧ��\n");
	system("pause");
}
void deleteVision(DuLinkedList *L)
{
	if (L != NULL)
	{
		DestroyList_DuL(L);
		L = NULL;
		printf("ɾ���ɹ�\n");
	}
	else printf("��������\n");
	system("pause");
}
void insertVision(DuLinkedList *L)
{
	system("cls");
	int a, c;
	DuLNode *p;
	while (1)
	{
		printf("1.��ѡ��Ľڵ�֮ǰ����\n");
		printf("2.��ѡ��Ľڵ�֮�����\n");
		scanf("%d", &a);
		if (a == 1 || a == 2)break;
		else printf("�����������������\n");
	}
	printf("������Ҫ����ڵ��λ��\n");
	scanf("%d", &c);
	p = (DuLNode*)malloc(sizeof(DuLNode));
	p->data = c;
	p->next = p->prior = NULL;
	if (a == 1)
	{
		int b;
		Status s;
		printf("������Ŀ��ڵ������\n");
		scanf("%d", &b);
		s = InsertBeforeList_DuL(search_DuL(L, &b), p);
		if (s == SUCCESS)printf("����ɹ�");
		else printf("����ʧ��\n");
	}
	if (a == 2)
	{
		int b;
		Status s;
		printf("������Ŀ��ڵ������\n");
		scanf("%d", &b);
		s = InsertAfterList_DuL(search_DuL(L, &b), p);
		if (s == SUCCESS)printf("����ɹ�");
		else printf("����ʧ��\n");
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
