 #include "../head/LinkStack.h" 
 #include "LinkStack.c" 

 int main(){
	LinkStack L;
	ElemType e;
		while (1) {
			system("cls");
			printf("                   链栈作业                               \n" 
				  "               -----请选择:-----\n"
			       "      ************系统功能菜单**************   \n"
			       "-----------------------------------------------\n"
			       "***********************************************\n"
			       "*  1.初始化栈       * *    2.判断是否为空栈   *\n"
			       "***********************************************\n"
			       "*  3.得到栈顶元素   * *    4.清空栈            *\n"
			       "***********************************************\n"
			       "*  5.销毁栈         * *    6.检测栈长度       *\n"
			       "***********************************************\n"
			       "*  7.入栈           * *    8.出栈             *\n"
			       "***********************************************\n"
			       "*              0.销毁栈并退出系统             *\n"
			       "***********************************************\n"
			       "***********************************************\n"
			       "-----------------------------------------------\n"
			       "请选择菜单编号:\n" );
			int i;
			numJudge(&i);
			switch (i) {
				case 1:
					initLStack(&L);
					system("pause");
					break;
				case 2:
					isEmptyLStack(L);
					system("pause");
					break;
				case 3:
					getTopLStack(L,&e);
					system("pause");
					break;
				case 4:
					clearLStack(&L); 
				system("pause");
					break;
				case 5:
					destroyLStack(&L);
				system("pause");
					break;
				case 6:
					LStackLength(L,&e);
				system("pause");
					break;
				case 7:
					pushLStack(L); 
				system("pause");
					break;
				case 8:
					popLStack(L);
					system("pause");
					break;
				case 0:
				destroyLStack(&L);
					return 0;
				default:
					printf("请输入有效数字!\n");
					system("pause");
					break;
			}
	
		}
	return 0;
 }
 
 
