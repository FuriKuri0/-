#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
     int pointer;
     int a;
     struct LNode *next;
}LNode,*LinkedList;
LinkedList createLinkedList(int a);
int addtoLinkedList(int a,int b,LinkedList L);
int deleteLinkedList(int a,LinkedList L);
int changeLinkedList(int a,int b,LinkedList L);
LinkedList create(void);
void deleteNode(LinkedList L);
void alter(LinkedList L);
void show(LinkedList L);
void destoryList(LinkedList L);
