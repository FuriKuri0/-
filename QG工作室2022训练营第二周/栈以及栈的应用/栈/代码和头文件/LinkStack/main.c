 #include "../head/LinkStack.h" 
 #include "LinkStack.c" 

 int main(){
	LinkStack L;
	ElemType e;
		while (1) {
			system("cls");
			printf("                   ��ջ��ҵ                               \n" 
				  "               -----��ѡ��:-----\n"
			       "      ************ϵͳ���ܲ˵�**************   \n"
			       "-----------------------------------------------\n"
			       "***********************************************\n"
			       "*  1.��ʼ��ջ       * *    2.�ж��Ƿ�Ϊ��ջ   *\n"
			       "***********************************************\n"
			       "*  3.�õ�ջ��Ԫ��   * *    4.���ջ            *\n"
			       "***********************************************\n"
			       "*  5.����ջ         * *    6.���ջ����       *\n"
			       "***********************************************\n"
			       "*  7.��ջ           * *    8.��ջ             *\n"
			       "***********************************************\n"
			       "*              0.����ջ���˳�ϵͳ             *\n"
			       "***********************************************\n"
			       "***********************************************\n"
			       "-----------------------------------------------\n"
			       "��ѡ��˵����:\n" );
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
					printf("��������Ч����!\n");
					system("pause");
					break;
			}
	
		}
	return 0;
 }
 
 
