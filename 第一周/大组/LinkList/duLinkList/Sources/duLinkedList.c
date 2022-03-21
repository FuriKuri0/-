#include "duLinkedList.h"
Status InitList_DuL(DuLinkedList *L);
Status DuListPrint(DuLinkedList L);
Status  InsertDuList(DuLinkedList L);
Status DeleteDuList(DuLinkedList L);
Status Delete (DuLinkedList L);
Status Repair (DuLinkedList L);
Status FindMidNode(DuLinkedList L);
Status SearchDuList(DuLinkedList L);
Status DestroyDuList(DuLinkedList *L);
int main() {
	DuLinkedList L;
	while (1) {
		printf( "                  ˫������ҵ                               \n" 
				"               -----��ѡ��:-----\n"
		       "      ************ϵͳ���ܲ˵�**************\n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.����������       * *    2.�����½ڵ�     *\n"
		       "***********************************************\n"
		       "*  3.�������         * *    4.�ҵ�˫�����е� *\n"
		       "***********************************************\n"
		       "*  5.��ѯ���ݴ���    * *     6.ɾ���ڵ�ȡֵ  *\n"
		       "***********************************************\n"
		       "*             0.ɾ�������˳�                *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "��ѡ��˵����:\n" );
		int i;
		scanf("%d", &i);
		switch (i) {
			case 1:
				InitList_DuL(&L);
				break;
			case 2:
				InsertDuList(L);
				break;
			case 3:
				DuListPrint(L);
				break;
			case 4:
				FindMidNode(L);
				break;
			case 5:
				SearchDuList(L);
				break;
			case 6:
				DeleteDuList(L);
				break;
			case 0:
				DestroyDuList(&L);
				return 0;
				break;
			default:
				printf("��������Ч����!\n");
				break;
		}
	}
	return 0;
}

Status InitList_DuL(DuLinkedList *L) {
	if (((*L) = malloc(sizeof(DuLNode))) == NULL) {
		return ERROR;
	}
	(*L)->next = NULL;
	(*L)->prior = NULL;
	DuLinkedList pRear;
	pRear = *L;
	printf("�����ɹ�!\n");
	ElemType val = -1;
	int count = 1;
	while (1) {
		printf("�������%d���ڵ����ֵ:(����-1ֹͣ����)\n", count++);
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		DuLinkedList new;
		new = malloc(sizeof(DuLNode));
		new->data = val;
		new->next = NULL;
		new->prior = pRear;
		pRear->next = new;
		pRear = new;
	}
	pRear->next = (*L);
	(*L)->prior = pRear;
	return SUCCESS;
}

Status DuListPrint(DuLinkedList L) {
	DuLinkedList p;
	p = malloc(sizeof(DuLNode));
	p = L;
	if (p->next == p) {
		printf("����������!\n");
		return ERROR;
	}
	printf("%d(β���)", L->prior->data);
	while (p->next != L) {
		printf("<-%d->", p->next->data);
		p = p->next;
	}
	printf("%d(ͷ���)\n", p->next->next->data);
	return SUCCESS;
}
Status  InsertDuList(DuLinkedList L) {
	DuLinkedList cur = L;
	printf("������Ҫ�������λ�ã�\n");
	int position;
	scanf("%d", &position);
	printf("������������ֵ��\n");
	ElemType val;
	scanf("%d", &val);
	DuLNode* insert;
	insert = malloc(sizeof(DuLNode));
	if (!insert) {
		return ERROR;
	}
	insert->data = val;
	while (--position) { //����ǰһλ��
		cur = cur->next;
	}
	insert->next = cur->next;
	insert->prior = cur;
	cur->next = insert;
	insert->next->prior = insert;
	printf("�������Ϊ:\n");
	DuListPrint(L);
	return SUCCESS;

}
Status DeleteDuList(DuLinkedList L) {
	while (1) {
		printf("-----��ѡ��------\n");
		printf("-----1��ɾ�����------\n");
		printf("-----2���޸Ľ��------\n");
		printf("-----3���˳��޸�------\n");
		int i;
		scanf("%d", &i);
		switch (i) {
			case 1:
				Delete (L);
				break;
			case 2:
				Repair(L);
				break;
			case 3:
				return SUCCESS;
				break;
			default:
				printf("��������Ч���֣�\n");
				break;
		}
	}
}
Status Delete (DuLinkedList L) {
	DuLinkedList cur = L;
	printf("������Ҫɾ������λ�ã�\n");
	int position;
	scanf("%d", &position);
	while (--position) { //����ǰһλ��
		cur = cur->next;
	}
	DuLinkedList temp = cur->next;
	cur->next = cur->next->next;
	cur->next->prior = cur;
	free(temp);
	printf("�������Ϊ:\n");
	DuListPrint(L);
	return SUCCESS;

}

Status Repair (DuLinkedList L) {
	DuLinkedList cur = L;
	printf("������Ҫ�޸Ľ���λ�ã�\n");
	int position;
	scanf("%d", &position);
	while (--position) { //����ǰһλ��
		cur = cur->next;
	}
	printf("�������޸ĺ��ֵΪ:\n");
	ElemType val;
	scanf("%d", &val);
	cur->next->data = val;
	printf("�������Ϊ:\n");
	DuListPrint(L);
	return SUCCESS;

}
Status FindMidNode(DuLinkedList L) {
	if (L->next == NULL) {
		printf("���������ݣ�\n");
		return ERROR;
	}
	if (L->next->next == NULL) {
		printf("�м�ڵ��ֵΪ:%d", L->next->data);
		return ERROR;
	}
	DuLinkedList fast, slow;
	fast = malloc(sizeof(DuLNode));
	slow = malloc(sizeof(DuLNode));
	fast = L->next;
	slow = L->next;
	while (fast->next!=L&&fast!=L) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("�м�ڵ��ֵΪ:%d", slow->data);
	return SUCCESS;
}
Status SearchDuList(DuLinkedList L){
	printf("������Ҫ���ҵĽ������:\n");
	ElemType val;
	scanf("%d",&val);
	DuLinkedList search;
	if((search=malloc(sizeof(DuLNode)))==NULL){
		printf("�޷������ڴ棡\n");
	}
	search=L->next;
	while(search!=L){
		if(search->data==val){
			printf("�������д�����!\n");
			return SUCCESS;
		}
		search=search->next;
	} 
	printf("�������޴����ݣ�\n");
	return SUCCESS; 
}
Status DestroyDuList(DuLinkedList *L){
	if((*L)->next==NULL){
		free(*L);
		return SUCCESS;
	}
	DuLinkedList p,q;
	p=(*L)->next;
	while(p!=L){
		q=p;
		p=p->next;
		free(q);
	}
	(*L)->next=NULL;
	(*L)->prior=NULL;
	return SUCCESS;
}
