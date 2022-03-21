#include "linkedList.h"


int main() {
	LinkedList L;
	while (1) {
		printf("                  单链表作业                               \n" 
			  "               -----请选择:-----\n"
		       "      ************系统功能菜单**************\n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.创建新链表       * *    2.插入新节点     *\n"
		       "***********************************************\n"
		       "*  3.输出链表         * *    4.将链表反向     *\n"
		       "***********************************************\n"
		       "*  5.找到单链表中点   * *    6.判断是否成环   *\n"
		       "***********************************************\n"
		       "*  7.删除节点取值     * *    8.查询数据存在   *\n"
		       "***********************************************\n"
		       "*              0.删除链表并退出系统           *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "请选择菜单编号:\n" );
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
				printf("请输入有效数字!\n");
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
	printf("创建成功!\n");
	ElemType val = -1;
	int count = 1;
	while (1) {
		printf("请输入第%d个节点的数值:(输入-1停止输入)\n", count++);
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
		printf("链表无数据!\n");
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
	printf("请输入要插入结点的位置：\n");
	int position;
	scanf("%d", &position);
	printf("请输入插入结点的值：\n");
	ElemType val;
	scanf("%d", &val);
	LNode* insert;
	insert = malloc(sizeof(LNode));
	if (!insert) {
		return ERROR;
	}
	insert->data = val;
	while (--position) { //来到前一位置
		cur = cur->next;
	}
	insert->next = cur->next;
	cur->next = insert;
	printf("最新链表为:\n");
	listPrint(L);
	return SUCCESS;
}
Status DeleteList(LNode *p) {
	while (1) {
		printf("-----请选择------\n");
		printf("-----1、删除结点------\n");
		printf("-----2、修改结点------\n");
		printf("-----3、退出修改------\n");
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
				printf("请输入有效数字！\n");
				break;
		}
	}

}
Status Delete (LinkedList L) {
	LinkedList cur = L;
	printf("请输入要删除结点的位置：\n");
	int position;
	scanf("%d", &position);
	while (--position) { //来到前一位置
		cur = cur->next;
	}
	LNode* temp = cur->next;
	cur->next = cur->next->next;
	free(temp);
	printf("链表更新为:\n");
	listPrint(L);
	return SUCCESS;

}
Status Repair (LinkedList L) {
	LinkedList cur = L;
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
	listPrint(L);
	return SUCCESS;

}
Status ReverseList(LinkedList *L) {
	LinkedList cur, pre, later;
	if ((*L)->next == NULL) {
		printf("链表无数据!\n");
		return SUCCESS;
	}
	if ((*L)->next->next == NULL) {
		printf("链表更新为:\n");
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
	cur->next = pre; //最后一个结点
	(*L)->next = cur; //将头结点指向最后节点，也就是反转后的头结点。
	printf("链表更新为:\n");
	listPrint(*L);
	return SUCCESS;
}
Status FindMidNode(LinkedList L) {
	if (L->next == NULL) {
		printf("链表无数据！\n");
		return ERROR;
	}
	if (L->next->next == NULL) {
		printf("中间节点的值为:%d", L->next->data);
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
	printf("中间节点的值为:%d", slow->data);
	return SUCCESS;
}
Status IsLoopList(LinkedList L) {
	if (L->next == NULL || L->next->next == NULL || L->next->next->next == NULL) { //结点为0,1,2时不成环
		printf("链表不成环!");
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
			printf("链表成环!\n");
			return SUCCESS;
		}
	}
	printf("链表不成环!");
	return SUCCESS;
}
Status SearchList(LinkedList L){
	printf("请输入要查找的结点数据:\n");
	ElemType val;
	scanf("%d",&val);
	LinkedList search;
	if((search=malloc(sizeof(LNode)))==NULL){
		printf("无法分配内存！\n");
	}
	search=L->next;
	while(search!=NULL){
		if(search->data==val){
			printf("链表中有此数据!\n");
			return SUCCESS;
		}
		search=search->next;
	} 
	printf("链表中无此数据！\n");
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
