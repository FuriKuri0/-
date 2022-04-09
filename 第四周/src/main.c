
#include"../inc/binary_sort_tree.h"
int main() {
	BinarySortTreePtr tree;
	tree = NULL;
	while (1) {
		system("cls");
		printf("                  ��������ҵ                               \n"
		       "               -----��ѡ��:-----\n"
		       "      ************ϵͳ���ܲ˵�**************   \n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.��ʼ��       * *    2.�����ӡ   *\n"
		       "***********************************************\n"
		       "*  3.����           * *   4.�����ӡ           *\n"
		       "***********************************************\n"
		       "*  5.�����ӡ         * *   6.�����ӡ       *\n"
		       "***********************************************\n"
		       "*               7.ɾ�����          *\n"
		       "***********************************************\n"
		       "*               8.���ҽ��          *\n"
		       "***********************************\n"
		       "*              0.�˳�ϵͳ             *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "��ѡ��˵����:\n" );
		int i;
		numJudge(&i);
		switch (i) {
			case 1:
				BST_init(&tree);
				system("pause");
				break;
			case 2:
				if (judge(tree)) {
					printf("����ݹ飺\n");
					BST_inorderR(tree->root);
					printf("\n");
					BST_inorderI(tree->root);
				}
				system("pause");
				break;
			case 3:
				BST_insert(tree);
				system("pause");
				break;
			case 4:
				if (judge(tree)) {
					printf("����ݹ飺\n");
					BST_postorderR(tree->root);
					printf("\n");
					BST_postorderI(*(tree->root));
				}
				system("pause");
				break;
			case 5:
				if (judge(tree)) {
					printf("����ݹ飺\n");
					BST_preorderR(tree->root);
					printf("\n");
					BST_preorderI(*(tree->root));
				}
				system("pause");
				break;
			case 6:
				if (judge(tree)) {
					printf("�����ӡ��\n");
					BST_levelOrder(tree->root);
				}
				system("pause");
				break;
			case 7:
				if (judge(tree)) {
					printf("������Ҫɾ����ֵ:\n");
					int key;
					numJudge(&key);
					BST_delete(&(tree->root), key);
				}
				system("pause");
				break;
			case 8:
				if (judge(tree)) {
					printf("������Ҫ���ҵ�ֵ:\n");
					int key;
					numJudge(&key);
					NodePtr p;
					if(BST_search(tree->root,key,NULL,&p)){
						printf("���ڸý��\n");
					}
				}
				system("pause");
				break;
			default:
				printf("��������Ч����!\n");
				system("pause");
				break;
		}

	}
	return 0;
}


