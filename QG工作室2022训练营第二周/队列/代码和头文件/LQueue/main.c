#include "../head/LQueue.h"
#include "LQueue.c"
int main() {
	LQueue L;
	while (1) {
		system("cls");
		printf("                   ������ҵ                    \n"
		       "               -----��ѡ��:-----\n"
		       "      ************ϵͳ���ܲ˵�**************   \n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.��ʼ������       * *    2.�ж��Ƿ�Ϊ��   *\n"
		       "***********************************************\n"
		       "*  3.�õ�����ǰ��Ԫ�� * *    4.��ն���       *\n"
		       "***********************************************\n"
		       "*  5.���ٶ���         * *    6.�����г���   *\n"
		       "***********************************************\n"
		       "*  7.�����           * *    8.������         *\n"
		       "***********************************************\n"
		       "*              9.��ӡ����                     *\n"
		       "***********************************************\n"
		       "*              0.���ٶ��в��˳�ϵͳ           *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "��ѡ��˵����:\n" );
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
				printf("��������Ч����!\n");
				system("pause");
				break;
		}

	}
	return 0;
}
