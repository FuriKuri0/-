#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}*LinkStack;



//��ջ
Status numJudge(int *a);//�ж������Ƿ�����
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack s,int *length);//���ջ����
Status pushLStack(LinkStack s);//��ջ
Status popLStack(LinkStack s);//��ջ


#endif 
