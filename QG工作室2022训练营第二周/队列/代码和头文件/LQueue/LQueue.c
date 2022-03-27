#include "../head/LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	(*Q) = malloc(sizeof(struct Lqueue));
	(*Q)->length = 0;
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	int count = 1;
	printf("请输入队列长度:\n");
	int leng;
	scanf("%d", &leng);
	(*Q)->length = leng;
	while (leng--) {
		printf("请输入第%d个元素的类型（数字或字符、字符串）\n", count);
		scanf("%s", datatype);
		if (strcmp("数字", datatype) == 0) {
			printf("请输入第%d个元素的值\n", count++);
			int* num;
			num = malloc(sizeof(int));
			numJudge(num);
			Node *p = malloc(sizeof(Node));
			p->type = 1;
			p->data = NULL;
			p->data = num;
			p->next = NULL;
			if (count == 2) {
				(*Q)->front = p;
				(*Q)->rear = p;
			} else {
				(*Q)->rear->next = p;
				(*Q)->rear = p;
			}
		} else if (strcmp("字符", datatype) == 0) {
			getchar();
			printf("请输入第%d个元素的值\n", count++);
			char *zifu;
			zifu = malloc(sizeof(char));
			scanf("%c", &zifu);
			Node *p = malloc(sizeof(Node));
			p->type = 2;
			p->data = NULL;
			p->data = zifu;
			p->next = NULL;
			if (count == 2) {
				(*Q)->front = p;
				(*Q)->rear = p;
			} else {
				(*Q)->rear->next = p;
				(*Q)->rear = p;
			}
		} else if (strcmp("字符串", datatype) == 0) {
			printf("请输入第%d个元素的值\n", count++);
			char *zifuchuan;
			zifuchuan = (char*)malloc(sizeof(1000));
			scanf("%s", zifuchuan);
			Node *p = malloc(sizeof(Node));
			p->type = 3;
			p->data = NULL;
			p->data = zifuchuan;
			p->next = NULL;
			if (count == 2) {
				(*Q)->front = p;
				(*Q)->rear = p;
			} else {
				(*Q)->rear->next = p;
				(*Q)->rear = p;
			}
		} else {
			printf("请输入指定的数据类型\n");
			leng++;
		}
	}
	printf("长度是%d\n", (*Q)->length);
	printf("队列初始化完成！\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	ClearLQueue(Q);
	free((*Q)->front);
	printf("队列已销毁！\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue Q) {
	if (Q->length == 0) {
		printf("队列为空!\n");
		return TRUE;
	} else if (Q->length > 0) {
		printf("队列不为空!\n");
		return TRUE;
	} else if (Q->length < 0) {
		printf("错误!\n");
		return FALSE;
	}
} 
	/**
	 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
	 *    @description : 查看队头元素
	 *    @param         Q e 队列指针Q,返回数据指针e
	 *    @return         : 成功-TRUE; 失败-FALSE
	 *  @notice      : 队列是否空
	 */
	Status GetHeadLQueue(LQueue Q) {
		if (Q->length == 0) {
			printf("队列为空!\n");
			return TRUE;
		}
		printf("队列首元素为:\n");
		Node *temp;
		temp = malloc(sizeof(Node));
		temp = Q->front;
		if (temp->type == 1) {
			printf("%d\n", *(int *)temp->data);

		} else if (temp->type == 2) {
			printf("%c\n", (char *)temp->data);

		} else if (temp->type == 3) {
			printf("%s\n", temp->data);
		}

	}

	/**
	 *  @name        : int LengthLQueue(LQueue *Q)
	 *    @description : 确定队列长度
	 *    @param         Q 队列指针Q
	 *    @return         : 成功-TRUE; 失败-FALSE
	 *  @notice      : None
	 */
	void LengthLQueue(LQueue Q) {
		printf("队列长度为:%d\n", Q->length);
	}

	/**
	 *  @name        : Status EnLQueue(LQueue *Q, void *data)
	 *    @description : 入队操作
	 *    @param         Q 队列指针Q,入队数据指针data
	 *    @return         : 成功-TRUE; 失败-FALSE
	 *  @notice      : 队列是否为空
	 */
	Status EnLQueue(LQueue Q) {
		printf("请输入入队元素数量:\n");
		int leng;
		scanf("%d", &leng);
		int count = 1;
		int temp = leng;
		int flag = 0;
		while (temp--) {
			printf("请输入加入的第%d个元素的类型（数字或字符、字符串）\n", count);
			scanf("%s", datatype);
			if (strcmp("数字", datatype) == 0) {
				printf("请输入第%d个元素的值\n", count++);
				int* num;
				num = malloc(sizeof(int));
				numJudge(num);
				Node *p = malloc(sizeof(Node));
				p->type = 1;
				p->data = NULL;
				p->data = num;
				p->next = NULL;
				if (Q->length == 0 && flag != 1) {
					Q->front = p;
					Q->rear = p;
					flag = 1;
				} else {
					Q->rear->next = p;
					Q->rear = p;
				}
			} else if (strcmp("字符", datatype) == 0) {
				getchar();
				printf("请输入第%d个元素的值\n", count++);
				char *zifu;
				zifu = malloc(sizeof(char));
				scanf("%c", &zifu);
				Node *p = malloc(sizeof(Node));
				p->type = 2;
				p->data = NULL;
				p->data = zifu;
				p->next = NULL;
				if (Q->length == 0 && flag != 1) {
					Q->front = p;
					Q->rear = p;
					flag = 1;
				} else {
					Q->rear->next = p;
					Q->rear = p;
				}
			} else if (strcmp("字符串", datatype) == 0) {
				printf("请输入第%d个元素的值\n", count++);
				char *zifuchuan;
				zifuchuan = (char*)malloc(sizeof(1000));
				scanf("%s", zifuchuan);
				Node *p = malloc(sizeof(Node));
				p->type = 3;
				p->data = NULL;
				p->data = zifuchuan;
				p->next = NULL;
				if (Q->length == 0 && flag != 1) {
					Q->front = p;
					Q->rear = p;
					flag = 1;
				} else {
					Q->rear->next = p;
					Q->rear = p;
				}
			} else {
				printf("请输入指定的数据类型\n");
				temp++;
			}
		}
		Q->length += leng;
		printf("队列初始化完成！\n");
	}

	/**
	 *  @name        : Status DeLQueue(LQueue *Q)
	 *    @description : 出队操作
	 *    @param         Q 队列指针Q
	 *    @return         : 成功-TRUE; 失败-FALSE
	 *  @notice      : None
	 */
	Status DeLQueue(LQueue Q) {
		if (Q->length == 0) {
			printf("队列为空!\n");
			return TRUE;
		}
		printf("出队元素为:\n");
		Node *temp;
		temp = malloc(sizeof(Node));
		temp = Q->front;
		if (temp->type == 1) {
			printf("%d\n", *(int *)temp->data);

		} else if (temp->type == 2) {
			printf("%c\n", (char *)temp->data);

		} else if (temp->type == 3) {
			printf("%s\n", temp->data);
		}
		Q->length--;
		Q->front = Q->front->next;
		free(temp);
	}

	/**
	 *  @name        : void ClearLQueue(AQueue *Q)
	 *    @description : 清空队列
	 *    @param         Q 队列指针Q
	 *  @notice      : None
	 */
	void ClearLQueue(LQueue * Q) {
		Node *temp;
		temp = (*Q)->front;
		while ((*Q)->length--) {
			(*Q)->front = (*Q)->front->next;
			free(temp);
		}
		(*Q)->length++;
		printf("队列已清空！\n");
	}

	/**
	 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
	 *    @description : 遍历函数操作
	 *    @param         Q 队列指针Q，操作函数指针foo
	 *    @return         : None
	 *  @notice      : None
	 */
//Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
//
//}

	/**
	 *  @name        : void LPrint(void *q)
	 *    @description : 操作函数
	 *    @param         q 指针q

	 *  @notice      : None
	 */
	void LPrint(LQueue Q) {
		if (Q->length == 0) {
			printf("队列为空!\n");
			return TRUE;
		}
		printf("该链表为:\n（队头）");
		Node *temp;
		temp = malloc(sizeof(Node));
		temp = Q->front;
		int numtemp=Q->length;
		while (numtemp--) {
			if (temp->type == 1) {
				printf("%d<-", *(int *)temp->data);
				temp = temp->next;
			} else if (temp->type == 2) {
				printf("%c<-", (char *)temp->data);
				temp = temp->next;
			} else if (temp->type == 3) {
				printf("%s<-", temp->data);
				temp = temp->next;
			}
		}	
		printf("队尾\n");
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
		return TRUE;
	}

	/**************************************************************
	 *    End-Multi-Include-Prevent Section
	 **************************************************************/
//#endif // LQUEUE_H_INCLUDED
