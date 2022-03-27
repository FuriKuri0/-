#include "../head/LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	(*Q) = malloc(sizeof(struct Lqueue));
	(*Q)->length = 0;
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	int count = 1;
	printf("��������г���:\n");
	int leng;
	scanf("%d", &leng);
	(*Q)->length = leng;
	while (leng--) {
		printf("�������%d��Ԫ�ص����ͣ����ֻ��ַ����ַ�����\n", count);
		scanf("%s", datatype);
		if (strcmp("����", datatype) == 0) {
			printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
		} else if (strcmp("�ַ�", datatype) == 0) {
			getchar();
			printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
		} else if (strcmp("�ַ���", datatype) == 0) {
			printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
			printf("������ָ������������\n");
			leng++;
		}
	}
	printf("������%d\n", (*Q)->length);
	printf("���г�ʼ����ɣ�\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	ClearLQueue(Q);
	free((*Q)->front);
	printf("���������٣�\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue Q) {
	if (Q->length == 0) {
		printf("����Ϊ��!\n");
		return TRUE;
	} else if (Q->length > 0) {
		printf("���в�Ϊ��!\n");
		return TRUE;
	} else if (Q->length < 0) {
		printf("����!\n");
		return FALSE;
	}
} 
	/**
	 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
	 *    @description : �鿴��ͷԪ��
	 *    @param         Q e ����ָ��Q,��������ָ��e
	 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
	 *  @notice      : �����Ƿ��
	 */
	Status GetHeadLQueue(LQueue Q) {
		if (Q->length == 0) {
			printf("����Ϊ��!\n");
			return TRUE;
		}
		printf("������Ԫ��Ϊ:\n");
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
	 *    @description : ȷ�����г���
	 *    @param         Q ����ָ��Q
	 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
	 *  @notice      : None
	 */
	void LengthLQueue(LQueue Q) {
		printf("���г���Ϊ:%d\n", Q->length);
	}

	/**
	 *  @name        : Status EnLQueue(LQueue *Q, void *data)
	 *    @description : ��Ӳ���
	 *    @param         Q ����ָ��Q,�������ָ��data
	 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
	 *  @notice      : �����Ƿ�Ϊ��
	 */
	Status EnLQueue(LQueue Q) {
		printf("���������Ԫ������:\n");
		int leng;
		scanf("%d", &leng);
		int count = 1;
		int temp = leng;
		int flag = 0;
		while (temp--) {
			printf("���������ĵ�%d��Ԫ�ص����ͣ����ֻ��ַ����ַ�����\n", count);
			scanf("%s", datatype);
			if (strcmp("����", datatype) == 0) {
				printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
			} else if (strcmp("�ַ�", datatype) == 0) {
				getchar();
				printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
			} else if (strcmp("�ַ���", datatype) == 0) {
				printf("�������%d��Ԫ�ص�ֵ\n", count++);
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
				printf("������ָ������������\n");
				temp++;
			}
		}
		Q->length += leng;
		printf("���г�ʼ����ɣ�\n");
	}

	/**
	 *  @name        : Status DeLQueue(LQueue *Q)
	 *    @description : ���Ӳ���
	 *    @param         Q ����ָ��Q
	 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
	 *  @notice      : None
	 */
	Status DeLQueue(LQueue Q) {
		if (Q->length == 0) {
			printf("����Ϊ��!\n");
			return TRUE;
		}
		printf("����Ԫ��Ϊ:\n");
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
	 *    @description : ��ն���
	 *    @param         Q ����ָ��Q
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
		printf("��������գ�\n");
	}

	/**
	 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
	 *    @description : ������������
	 *    @param         Q ����ָ��Q����������ָ��foo
	 *    @return         : None
	 *  @notice      : None
	 */
//Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
//
//}

	/**
	 *  @name        : void LPrint(void *q)
	 *    @description : ��������
	 *    @param         q ָ��q

	 *  @notice      : None
	 */
	void LPrint(LQueue Q) {
		if (Q->length == 0) {
			printf("����Ϊ��!\n");
			return TRUE;
		}
		printf("������Ϊ:\n����ͷ��");
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
		printf("��β\n");
	}
	
	Status numJudge(int *a) {
		scanf("%d", a);
		int judge = getchar();
		while (judge != 10) {
			while (getchar() != '\n');
			printf("��������Ч���֣�\n");
			scanf("%d", a);
			judge = getchar();
		}
		return TRUE;
	}

	/**************************************************************
	 *    End-Multi-Include-Prevent Section
	 **************************************************************/
//#endif // LQUEUE_H_INCLUDED
