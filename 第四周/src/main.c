
#include"../inc/binary_sort_tree.h"
int main() {
	BinarySortTreePtr tree;
	tree = NULL;
	while (1) {
		system("cls");
		printf("                  二叉树作业                               \n"
		       "               -----请选择:-----\n"
		       "      ************系统功能菜单**************   \n"
		       "-----------------------------------------------\n"
		       "***********************************************\n"
		       "*  1.初始化       * *    2.中序打印   *\n"
		       "***********************************************\n"
		       "*  3.插入           * *   4.后序打印           *\n"
		       "***********************************************\n"
		       "*  5.先序打印         * *   6.层序打印       *\n"
		       "***********************************************\n"
		       "*               7.删除结点          *\n"
		       "***********************************************\n"
		       "*               8.查找结点          *\n"
		       "***********************************\n"
		       "*              0.退出系统             *\n"
		       "***********************************************\n"
		       "***********************************************\n"
		       "-----------------------------------------------\n"
		       "请选择菜单编号:\n" );
		int i;
		numJudge(&i);
		switch (i) {
			case 1:
				BST_init(&tree);
				system("pause");
				break;
			case 2:
				if (judge(tree)) {
					printf("中序递归：\n");
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
					printf("后序递归：\n");
					BST_postorderR(tree->root);
					printf("\n");
					BST_postorderI(*(tree->root));
				}
				system("pause");
				break;
			case 5:
				if (judge(tree)) {
					printf("先序递归：\n");
					BST_preorderR(tree->root);
					printf("\n");
					BST_preorderI(*(tree->root));
				}
				system("pause");
				break;
			case 6:
				if (judge(tree)) {
					printf("层序打印：\n");
					BST_levelOrder(tree->root);
				}
				system("pause");
				break;
			case 7:
				if (judge(tree)) {
					printf("请输入要删除的值:\n");
					int key;
					numJudge(&key);
					BST_delete(&(tree->root), key);
				}
				system("pause");
				break;
			case 8:
				if (judge(tree)) {
					printf("请输入要查找的值:\n");
					int key;
					numJudge(&key);
					NodePtr p;
					if(BST_search(tree->root,key,NULL,&p)){
						printf("存在该结点\n");
					}
				}
				system("pause");
				break;
			default:
				printf("请输入有效数字!\n");
				system("pause");
				break;
		}

	}
	return 0;
}


