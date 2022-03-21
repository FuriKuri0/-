#include "linkedList.h"


int main() {
	LinkedList L;
	while (1) {
		printf("                  ��������ҵ                               \n" 
			  "               -----��ѡ��:-----\n"
		       "      ************ϵͳ���ܲ˵�**************\n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.����������       * *    2.�����½ڵ�     *\n"
		       "***********************************************\n"
		       "*  3.�������         * *    4.��������     *\n"
		       "***********************************************\n"
		       "*  5.�ҵ��������е�   * *    6.�ж��Ƿ�ɻ�   *\n"
		       "***********************************************\n"
		       "*  7.ɾ���ڵ�ȡֵ     * *    8.��ѯ���ݴ���   *\n"
		       "***********************************************\n"
		       "*              0.ɾ�������˳�ϵͳ           *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "��ѡ��˵����:\n" );
		int i;
		scanf("%d", &i);
		switch (i) {
			case 1:
				InitList(&L);
				break;
			case 2:
				InsertList(L);
				break;
			case 3:
				listPrint(L);
				break;
			case 4:
				ReverseList(&L);
				break;
			case 5:
				FindMidNode(L);
				break;
			case 6:
				IsLoopList(L);
				break;
			case 7:
				DeleteList(L);
				break;
			case 8:
				SearchList(L);
				break;
			case 0:
				DestroyList(&L);
				return 0;
				break;
			default:
				printf("��������Ч����!\n");
				break;
		}

	}
	return 0;
}

Status InitList(LinkedList *L) {
	if (((*L) = malloc(sizeof(LNode))) == NULL) {
		return ERROR;
	}
	(*L)->next = NULL;
	LinkedList pRear = *L;
	printf("�����ɹ�!\n");
	ElemType val = -1;
	int count = 1;
	while (1) {
		printf("�������%d���ڵ����ֵ:(����-1ֹͣ����)\n", count++);
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		LinkedList new = malloc(sizeof(LNode));
		new->data = val;
		new->next = NULL;
		pRear->next = new;
		pRear = new;
	}
	return SUCCESS;
}
Status listPrint(LinkedList L) {
	if (L->next == NULL) {
		printf("����������!\n");
		return ERROR;
	}
	LinkedList p = L;
	while (p->next != NULL) {
		printf("%d->", p->next->data);
		p = p->next;
	}
	printf("NULL\n");
}

Status InsertList(LinkedList L) {
	LinkedList cur = L;
	printf("������Ҫ�������λ�ã�\n");
	int position;
	scanf("%d", &position);
	printf("������������ֵ��\n");
	ElemType val;
	scanf("%d", &val);
	LNode* insert;
	insert = malloc(sizeof(LNode));
	if (!insert) {
		return ERROR;
	}
	insert->data = val;
	while (--position) { //����ǰһλ��
		cur = cur->next;
	}
	insert->next = cur->next;
	cur->next = insert;
	printf("��������Ϊ:\n");
	listPrint(L);
	return SUCCESS;
}
Status DeleteList(LNode *p) {
	while (1) {
		printf("-----��ѡ��------\n");
		printf("-----1��ɾ�����------\n");
		printf("-----2���޸Ľ��------\n");
		printf("-----3���˳��޸�------\n");
		int i;
		scanf("%d", &i);
		switch (i) {
			case 1:
				Delete (p);
				break;
			case 2:
				Repair(p);
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
Status Delete (LinkedList L) {
	LinkedList cur = L;
	printf("������Ҫɾ������λ�ã�\n");
	int position;
	scanf("%d", &position);
	while (--position) { //����ǰһλ��
		cur = cur->next;
	}
	LNode* temp = cur->next;
	cur->next = cur->next->next;
	free(temp);
	printf("�������Ϊ:\n");
	listPrint(L);
	return SUCCESS;

}
Status Repair (LinkedList L) {
	LinkedList cur = L;
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
	listPrint(L);
	return SUCCESS;

}
Status ReverseList(LinkedList *L) {
	LinkedList cur, pre, later;
	if ((*L)->next == NULL) {
		printf("����������!\n");
		return SUCCESS;
	}
	if ((*L)->next->next == NULL) {
		printf("�������Ϊ:\n");
		listPrint(*L);
		return SUCCESS;
	}
	if ((*L)->next->next->next == NULL) {
		cur = malloc(sizeof(LNode));
		cur = (*L)->next->next;
		(*L)->next->next = NULL;
		cur->next = (*L)->next;
		(*L)->next = cur;
		return SUCCESS;
	}
	cur = malloc(sizeof(LNode));
	pre = malloc(sizeof(LNode));
	later = malloc(sizeof(LNode));
	pre = (*L)->next;
	cur = (*L)->next->next;
	later = (*L)->next->next->next;
	pre->next = NULL;
	while (later != NULL) {
		cur->next = pre;
		pre = cur;
		cur = later;
		later = later->next;
	}
	cur->next = pre; //���һ�����
	(*L)->next = cur; //��ͷ���ָ�����ڵ㣬Ҳ���Ƿ�ת���ͷ��㡣
	printf("�������Ϊ:\n");
	listPrint(*L);
	return SUCCESS;
}
Status FindMidNode(LinkedList L) {
	if (L->next == NULL) {
		printf("���������ݣ�\n");
		return ERROR;
	}
	if (L->next->next == NULL) {
		printf("�м�ڵ��ֵΪ:%d", L->next->data);
		return ERROR;
	}
	LinkedList fast, slow;
	fast = malloc(sizeof(LNode));
	slow = malloc(sizeof(LNode));
	fast = L->next;
	slow = L->next;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("�м�ڵ��ֵΪ:%d", slow->data);
	return SUCCESS;
}
Status IsLoopList(LinkedList L) {
	if (L->next == NULL || L->next->next == NULL || L->next->next->next == NULL) { //���Ϊ0,1,2ʱ���ɻ�
		printf("�����ɻ�!");
		return ERROR;
	}
	LinkedList fast, slow;
	fast = malloc(sizeof(LNode));
	slow = malloc(sizeof(LNode));
	fast = L->next;
	slow = L->next;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			printf("����ɻ�!\n");
			return SUCCESS;
		}
	}
	printf("�����ɻ�!");
	return SUCCESS;
}
Status SearchList(LinkedList L){
	printf("������Ҫ���ҵĽ������:\n");
	ElemType val;
	scanf("%d",&val);
	LinkedList search;
	if((search=malloc(sizeof(LNode)))==NULL){
		printf("�޷������ڴ棡\n");
	}
	search=L->next;
	while(search!=NULL){
		if(search->data==val){
			printf("�������д�����!\n");
			return SUCCESS;
		}
		search=search->next;
	} 
	printf("�������޴����ݣ�\n");
	return SUCCESS; 
}

Status DestroyList(LinkedList *L){
	if((*L)->next==NULL){
		free(*L);
		return SUCCESS;
	}
	LinkedList p,q;
	p=(*L)->next;
	while(p){
		q=p;
		p=p->next;
		free(q);
	}
	(*L)->next=NULL;
	return SUCCESS;
}
