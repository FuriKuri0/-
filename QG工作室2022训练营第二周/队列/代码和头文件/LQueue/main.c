#include "../head/LQueue.h"
#include "LQueue.c"
int main() {
	LQueue L;
	while (1) {
		system("cls");
		printf("                   队列作业                    \n"
		       "               -----请选择:-----\n"
		       "      ************系统功能菜单**************   \n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.初始化队列       * *    2.判断是否为空   *\n"
		       "***********************************************\n"
		       "*  3.得到队列前端元素 * *    4.清空队列       *\n"
		       "***********************************************\n"
		       "*  5.销毁队列         * *    6.检测队列长度   *\n"
		       "***********************************************\n"
		       "*  7.入队列           * *    8.出队列         *\n"
		       "***********************************************\n"
		       "*              9.打印队列                     *\n"
		       "***********************************************\n"
		       "*              0.销毁队列并退出系统           *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "请选择菜单编号:\n" );
		int i;
		numJudge(&i);
		switch (i) {
			case 1:
				InitLQueue(&L);
				system("pause");
				break;
			case 2:
				IsEmptyLQueue(L);
				system("pause");
				break;
			case 3:
				GetHeadLQueue(L);
				system("pause");
				break;
			case 4:
				ClearLQueue(&L);
				system("pause");
				break;
			case 5:
				DestoryLQueue(&L) ;
				system("pause");
				break;
			case 6:
				LengthLQueue(L);
				system("pause");
				break;
			case 7:
				EnLQueue(L);
				system("pause");
				break;
			case 8:
				DeLQueue(L);
				system("pause");
				break;
			case 9:
				LPrint(L);
				system("pause");
				break;
			case 0:
				DestoryLQueue(&L);
				system("pause");
				return 0; 
			default:
				printf("请输入有效数字!\n");
				system("pause");
				break;
		}

	}
	return 0;
}
