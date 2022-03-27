#include<stdio.h>
#include<stdlib.h>
#define n 50
#pragma warning(disable:4996)
typedef struct {
	char a[n];
	int size;//表示栈中含有的元素数量
} stack;
typedef struct {
	int a[n];
	int size;//表示栈中含有的元素数量
} numstack;
char pop(stack *p) {
	--(p->size);
	return p->a[p->size];
}

char top(stack *p) {
	if (p->size == 0)
		return '/0';//抛出/0字符代表空
	else {
		return p->a[p->size - 1];
	}
}
int empty(stack *p) {
	return p->size == 0;
}
void push(stack *p, char b) {
	p->a[p->size] = b;//栈顶元素为a[p->size-1]
	++p->size;
}
int popnum(numstack *p) {
	--(p->size);
	return p->a[p->size];
}
void pushnum(numstack *p, char b) {
	int ans = b - '0';
	p->a[p->size] = ans;//栈顶元素为a[p->size-1]
	++p->size;
}
int compare(char a) { //用于比较优先级
	int i;
	switch (a) {
		case '+':
			i = 1;
			break;
		case '-':
			i = 1;
			break;
		case '*':
			i = 2;
			break;
		case '/':
			i = 2;
			break;
		default:
			i = 0;
			break;
	}
	return i;
}
char merge(int a, int b, char c) { //用于将两数字合并,注意前面的数字传地址
	char ans;
//    printf("%d %d\n",a,b);
	if (c == '-') {
		ans = a - b + '0';
		return ans;
	} else if (c == '+') {
		ans = a + b + '0';
		   return ans;
	} else if (c == '*') {
		ans = a * b + '0';
		     return ans;
	} else {
		ans = a / b + '0';
		     return ans;
	}

}


void getValue(char arr[]) {
	stack* s;
	s = malloc(sizeof(stack)); //搞个栈
	s->size = 0;
	char suffix[10000];//后缀表达数组
	int num = 0; //用来定位后缀表达数组suffix
	int i = -1;
	while (arr[++i] != '=') {
		if (arr[i] == '\0')
				{
					printf("表达式末尾应该有‘=’");
					system("pause");
					return;
				}
		if (arr[i] >= '0' && arr[i] <= '9') {
			suffix[num++] = arr[i];
		}
//		6+(4-2)*3+9/3=
		else if (arr[i] == '(') {
			push(s, arr[i]);
		} else if (arr[i] == ')') {
			while (s->a[s->size - 1] != '(' && s->size != 0) {
				suffix[num++] = pop(s);
			}
			if (s->size != 0) {
				pop(s);
			}
		} else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
			while (s->size != 0) {
				if (compare(arr[i]) > compare(s->a[s->size - 1]) || s->a[s->size - 1] == '(') {
					push(s, arr[i]);
					break;
				} else {
					suffix[num++] = pop(s);
				}
			}
			if (s->size == 0) {
				push(s, arr[i]);
			}
		}
	}
	while (s->size != 0) {
		suffix[num++] = pop(s);
	}//至此得到后缀表达式
//	printf("%s\n",suffix);
	numstack* p;
	p = malloc(sizeof(numstack)); //搞个栈
	p->size = 0;
	int j = 0;
	for (j; j < num; j++) {
		if (suffix[j] >= '0' && suffix[j] <= '9')
			pushnum(p, suffix[j]);
		else {
			if (p->size >= 2) {
				pushnum(p, merge(popnum(p), popnum(p), suffix[j]));
			}
		}
	}
	printf("%d\n", p->a[p->size - 1]);
}



int main() {
	stack *p;
	char bds[50];
	scanf("%s", bds);
	getValue(bds);
	system("pause") ;
	return 0;
}
