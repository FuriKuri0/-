#include "head.h"
int createNumber;
LinkedList L;
int main()
{
	system("color 75");
	L = create();
	int i = 0;
	while (1)
	{
		system("cls");
		printf("��������ҵ\n");
		printf("1.�޸�����\n");
		printf("2.ɾ������\n");
		printf("3.�ݻ�����\n");
		printf("4.��ʾ����\n");
		printf("5.�˳�\n");
		scanf("%d", &i);
		switch (i)
		{
			case 1:
				alter(L);
				break;
			case 2:
				deleteNode(L);
				break;
			case 3:
				destoryList(L);
				L = NULL;
				break;
			case 4:
				show(L);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("������һ����Ч����\n");
				break;
		}
	}
	return 0;
}
LinkedList create()
{

	int a = 0;
	while (1)
	{
		system("cls");
		printf("���������������\n");
		scanf("%d", &a);
		break;
	}
	printf("�����ɹ���\n");
	system("pause");
	createNumber = 1;
	return createLinkedList(a);
}
void deleteNode(LinkedList L)
{
	system("cls");
	int a;
	printf("������Ҫɾ��Ԫ�ص�λ��\n");
	scanf("%d", &a);
	if (deleteLinkedList(a, L))printf("ɾ���ɹ�\n");
	else printf("ɾ��ʧ��,�Ҳ�����λ��\n");
	system("pause");
	main();
}
void alter(LinkedList L)
{
	while (1)
	{
		int m;
		system("cls");
		printf("1.�޸�Ԫ��\n");
		printf("2.����Ԫ��\n");
		scanf("%d", &m);
		if (m == 1)
		{
			system("cls");
			int a, b;
			printf("������Ҫ�޸�Ԫ�ص�λ��\n");
			scanf("%d", &a);
			printf("�������µ�ֵ\n");
			scanf("%d", &b);
			if (changeLinkedList(a, b, L))printf("�޸ĳɹ�\n");
			else printf("�޸�ʧ��,��λ�ò�����\n");
			system("pause");
			main();
		}
		if (m == 2)
		{
			system("cls");
			int a, b;
			printf("������Ҫ����Ԫ�ص�λ��\n");
			scanf("%d", &a);
			printf("�������µ�ֵ\n");
			scanf("%d", &b);
			if (addtoLinkedList(a, b, L))printf("����ɹ�\n");
			else printf("����ʧ��,�����޷�����\n");
			system("pause");
			main();
		}
	}

}
LinkedList createLinkedList(int a)
{
	LinkedList L = NULL;
	L = (LinkedList)malloc(sizeof(LNode));
	L->pointer = 1;
	L->a = a;
	L->next = NULL;
	return L;
}
int addtoLinkedList(int a, int b, LinkedList L)
{
	int i = 0;
	LinkedList p, p1, p2;
	p = L;
	p1 = (LinkedList)malloc(sizeof(LNode));
	p1->a = b;
	p1->next = NULL;
	p1->pointer = 0;
	if (L->next == NULL)
	{

		L->next = p1;
		return 1;
	}
	while (p && p->next)
	{
		p = p->next;
		if (i + 1 == a)break;
		i++;
	}
	if (i + 1 != a)return 0;
	else
	{
		p2 = p->next;
		p1->next = p2;
		p->next = p1;
	}

	return 1;

}
int deleteLinkedList(int a, LinkedList L)
{
	int i = 0;
	LinkedList p, p1;
	p = L;
	while (p->next)
	{
		p1 = p;
		p = p->next;
		if (i + 1 == a)break;
		i++;
	}
	if (!(i + 1 != a && L->next))return 0;
	else
	{
		p1->next = p->next;
		free(p);
		return 1;
	}
}
int changeLinkedList(int a, int b, LinkedList L)
{
	int i = 0;
	LinkedList p;
	p = L;
	while (p->next)
	{
		p = p->next;
		if (i + 1 == a)break;
		i++;
	}
	if (i + 1 != a && L->next)return 0;
	else
	{
		p->a = b;
		return 1;
	}
}
void show(LinkedList L)
{
	system("cls");
	LinkedList p;
	p = L;
	while (p)
	{
		if (p->pointer)printf("�������ƣ�%d\n", p->a);
		else
		{
			printf("%d", p->a);
			printf("->");
		}
		p = p->next;
	}
	if (p == NULL)printf("NULL\n");
	system("pause");
}
void destoryList(LinkedList L)
{
	system("cls");
	LinkedList p = L, p1;
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	L = NULL;
	createNumber = 0;
	printf("�ݻٳɹ�\n");
	system("pause");
}
