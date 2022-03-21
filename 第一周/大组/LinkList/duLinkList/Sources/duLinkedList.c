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
		printf( "                  双链表作业                               \n" 
				"               -----请选择:-----\n"
		       "      ************系统功能菜单**************\n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.创建新链表       * *    2.插入新节点     *\n"
		       "***********************************************\n"
		       "*  3.输出链表         * *    4.找到双链表中点 *\n"
		       "***********************************************\n"
		       "*  5.查询数据存在    * *     6.删除节点取值  *\n"
		       "***********************************************\n"
		       "*             0.删除链表并退出                *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "请选择菜单编号:\n" );
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
				printf("请输入有效数字!\n");
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
	printf("创建成功!\n");
	ElemType val = -1;
	int count = 1;
	while (1) {
		printf("请输入第%d个节点的数值:(输入-1停止输入)\n", count++);
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
		printf("链表无数据!\n");
		return ERROR;
	}
	printf("%d(尾结点)", L->prior->data);
	while (p->next != L) {
		printf("<-%d->", p->next->data);
		p = p->next;
	}
	printf("%d(头结点)\n", p->next->next->data);
	return SUCCESS;
}
Status  InsertDuList(DuLinkedList L) {
	DuLinkedList cur = L;
	printf("请输入要插入结点的位置：\n");
	int position;
	scanf("%d", &position);
	printf("请输入插入结点的值：\n");
	ElemType val;
	scanf("%d", &val);
	DuLNode* insert;
	insert = malloc(sizeof(DuLNode));
	if (!insert) {
		return ERROR;
	}
	insert->data = val;
	while (--position) { //来到前一位置
		cur = cur->next;
	}
	insert->next = cur->next;
	insert->prior = cur;
	cur->next = insert;
	insert->next->prior = insert;
	printf("链表更新为:\n");
	DuListPrint(L);
	return SUCCESS;

}
Status DeleteDuList(DuLinkedList L) {
	while (1) {
		printf("-----请选择------\n");
		printf("-----1、删除结点------\n");
		printf("-----2、修改结点------\n");
		printf("-----3、退出修改------\n");
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
				printf("请输入有效数字！\n");
				break;
		}
	}
}
Status Delete (DuLinkedList L) {
	DuLinkedList cur = L;
	printf("请输入要删除结点的位置：\n");
	int position;
	scanf("%d", &position);
	while (--position) { //来到前一位置
		cur = cur->next;
	}
	DuLinkedList temp = cur->next;
	cur->next = cur->next->next;
	cur->next->prior = cur;
	free(temp);
	printf("链表更新为:\n");
	DuListPrint(L);
	return SUCCESS;

}

Status Repair (DuLinkedList L) {
	DuLinkedList cur = L;
	printf("请输入要修改结点的位置：\n");
	int position;
	scanf("%d", &position);
	while (--position) { //来到前一位置
		cur = cur->next;
	}
	printf("请输入修改后的值为:\n");
	ElemType val;
	scanf("%d", &val);
	cur->next->data = val;
	printf("链表更新为:\n");
	DuListPrint(L);
	return SUCCESS;

}
Status FindMidNode(DuLinkedList L) {
	if (L->next == NULL) {
		printf("链表无数据！\n");
		return ERROR;
	}
	if (L->next->next == NULL) {
		printf("中间节点的值为:%d", L->next->data);
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
	printf("中间节点的值为:%d", slow->data);
	return SUCCESS;
}
Status SearchDuList(DuLinkedList L){
	printf("请输入要查找的结点数据:\n");
	ElemType val;
	scanf("%d",&val);
	DuLinkedList search;
	if((search=malloc(sizeof(DuLNode)))==NULL){
		printf("无法分配内存！\n");
	}
	search=L->next;
	while(search!=L){
		if(search->data==val){
			printf("链表中有此数据!\n");
			return SUCCESS;
		}
		search=search->next;
	} 
	printf("链表中无此数据！\n");
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
