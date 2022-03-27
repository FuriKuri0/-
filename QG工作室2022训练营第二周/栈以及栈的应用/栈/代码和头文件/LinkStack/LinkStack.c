#include "../head/LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	(*s)=(LinkStack *)malloc(sizeof(LinkStack));
	if(!s){
		printf("��ʼ��ʧ��!\n");
		return ERROR;
	} 
	(*s)->top=NULL;
	printf("��ʼ���ɹ�!\n");
	(*s)->count=0;
	int val=-1;
	int count=1;
	printf("�������%d���ڵ��ֵ:(����-1����)\n",count++);
	numJudge(&val);
	while(val!=-1){
		StackNode *temp;
		temp=malloc(sizeof(StackNode));
		if(!temp){
			printf("����ռ�ʧ�ܣ�\n");
			return ERROR;
		}
		temp->data=val;
		temp->next=(*s)->top;
		(*s)->count++;
		(*s)->top=temp;
		printf("�������%d���ڵ��ֵ:(����-1����)\n",count++);
		numJudge(&val);
	} 
	printf("��ʼ���ɹ�!\n");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack s){
	if(s->count==0){
		printf("ջΪ��!\n");
		return SUCCESS; 
	}
	printf("ջΪ����!\n");
			return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack s,ElemType *e){
	if(s->count==0){
		printf("ջΪ��!\n");
		return SUCCESS;
	}
	printf("ջ��Ԫ����:%d\n",e=s->top->data); 
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	while(--((*s)->count)){
		StackNode* temp;
		temp=(*s)->top;
		(*s)->top=(*s)->top->next;
		free(temp); 
	}
	printf("ջ�����!\n"); 
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	(*s)->top=NULL; 
	printf("ջ������!\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack s,int *length){
	printf("ջ�ĳ�����:%d\n",length=s->count);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack s){
	int val=-1;
		int count=1;
	printf("�������%d����ջ����ֵ:(����-1����)\n",count++);
		numJudge(&val);
		while(val!=-1){
			StackNode *temp;
			temp=malloc(sizeof(StackNode));
			if(!temp){
				printf("����ռ�ʧ�ܣ�\n");
				return ERROR;
			}
			temp->data=val;
			temp->next=s->top;
			s->count++;
			s->top=temp;
			printf("�������%d����ջ����ֵ:(����-1����)\n",count++);
			numJudge(&val);
		} 
		printf("��ջ�ɹ�!\n");
		return SUCCESS;
}

//��ջ
Status popLStack(LinkStack s){
	if(s->count==0){
		printf("���ǿ�ջ!\n");
	} 
	printf("��ջԪ��ֵΪ:%d\n",s->top->data);
	StackNode *temp=s->top;
	s->top=s->top->next;
	free(temp); 
	s->count--;
	return SUCCESS;
}
//�ж�����
Status numJudge(int *a){
	scanf("%d",a);
	int judge =getchar();
	while(judge!=10){
		while(getchar()!='\n');
		printf("��������Ч���֣�\n");
		scanf("%d",a);
		judge =getchar(); 
	}
	return SUCCESS; 
} 

