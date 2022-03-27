#include "../head/LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	(*s)=(LinkStack *)malloc(sizeof(LinkStack));
	if(!s){
		printf("初始化失败!\n");
		return ERROR;
	} 
	(*s)->top=NULL;
	printf("初始化成功!\n");
	(*s)->count=0;
	int val=-1;
	int count=1;
	printf("请输入第%d个节点的值:(输入-1结束)\n",count++);
	numJudge(&val);
	while(val!=-1){
		StackNode *temp;
		temp=malloc(sizeof(StackNode));
		if(!temp){
			printf("分配空间失败！\n");
			return ERROR;
		}
		temp->data=val;
		temp->next=(*s)->top;
		(*s)->count++;
		(*s)->top=temp;
		printf("请输入第%d个节点的值:(输入-1结束)\n",count++);
		numJudge(&val);
	} 
	printf("初始化成功!\n");
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack s){
	if(s->count==0){
		printf("栈为空!\n");
		return SUCCESS; 
	}
	printf("栈为不空!\n");
			return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack s,ElemType *e){
	if(s->count==0){
		printf("栈为空!\n");
		return SUCCESS;
	}
	printf("栈顶元素是:%d\n",e=s->top->data); 
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	while(--((*s)->count)){
		StackNode* temp;
		temp=(*s)->top;
		(*s)->top=(*s)->top->next;
		free(temp); 
	}
	printf("栈已清空!\n"); 
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s);
	(*s)->top=NULL; 
	printf("栈已销毁!\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack s,int *length){
	printf("栈的长度是:%d\n",length=s->count);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack s){
	int val=-1;
		int count=1;
	printf("请输入第%d个入栈结点的值:(输入-1结束)\n",count++);
		numJudge(&val);
		while(val!=-1){
			StackNode *temp;
			temp=malloc(sizeof(StackNode));
			if(!temp){
				printf("分配空间失败！\n");
				return ERROR;
			}
			temp->data=val;
			temp->next=s->top;
			s->count++;
			s->top=temp;
			printf("请输入第%d个入栈结点的值:(输入-1结束)\n",count++);
			numJudge(&val);
		} 
		printf("入栈成功!\n");
		return SUCCESS;
}

//出栈
Status popLStack(LinkStack s){
	if(s->count==0){
		printf("这是空栈!\n");
	} 
	printf("出栈元素值为:%d\n",s->top->data);
	StackNode *temp=s->top;
	s->top=s->top->next;
	free(temp); 
	s->count--;
	return SUCCESS;
}
//判断数字
Status numJudge(int *a){
	scanf("%d",a);
	int judge =getchar();
	while(judge!=10){
		while(getchar()!='\n');
		printf("请输入有效数字！\n");
		scanf("%d",a);
		judge =getchar(); 
	}
	return SUCCESS; 
} 

