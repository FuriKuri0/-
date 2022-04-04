
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
void swap(int *a, int i, int j);//交换数组元素 
int  getK(int *a,int k,int size);//得到第K大小 
void test(int testTime, int maxSize);//测试各个排序时间 
void Partition(int* a, int L, int R, int* b);
void getBigRandArr(int* arr, int maxValue, int maxLength);//得到随机数组 
void insertSort(int *a, int n);//插入排序 
//归并 
void MergeArray(int *a, int begin, int mid, int end);
void process(int *a, int begin, int end);
//快排 
void QuickSort_Recursion(int *a, int begin, int end);
//颜色 
void ColorSort(int *a, int size);
//基数 
void RadixCountSort(int *a, int size, int digit);
//计数 
void CountSort(int *a, int size, int max);
//打印 
void printArr(int *a, int length);
//得到数字a 第d位上的值，用于桶排序（基数） 
int getDight(int a, int d);
//计算位数 
int digit(int a);
//数组初始化 
void init(int *a, int length);
//生成随机数组并保存文件 
void save(int *arr, int maxValue, int maxLength);
//从文件中得到随机数组 
void get(int *a,int maxLength);
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void swap(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int digit(int a) {
	int res = 0;
	while (a) {
		a /= 10;
		res++;
	}
	return res;

}
void printArr(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d  ", arr[i]);
	}
}
//保存数据到文件夹
void save(int *arr, int maxValue, int maxLength) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxLength; i++) {
		arr[i] = rand() % maxValue + 1;
	}
	FILE *fp;
	fp = fopen("data.csv", "w");
	if (fp == NULL) {
		printf("File cant open!\n");
		exit(0);
	}
	for (int i = 0; i < maxLength; i++) {
		fprintf(fp, "%d,", arr[i]);
	}
	fclose(fp);
}
//从文件夹从获取数据
void get(int *a,int maxLength) {
	FILE *fp1;
	fp1 = fopen("data.csv", "r");
	for (int i = 0; i < maxLength; i++) {
		fscanf(fp1, "%d,", &a[i]);
	}
	printArr(a,maxLength); 
	fclose(fp1);
}
void getBigRandArr(int* arr, int maxValue, int maxLength) {
//	save(arr, maxValue, maxLength);
//	get(arr,maxLength);  
//该两行为生成数据且保存文件且从文件中读取数据中的方式来得到随即数组， 
//由于在小数据大次数情况下会严重拖慢速度，故建议在大数据小次数下使用，可取消注释
//使用时整个getBigRandArr只留下save和get即可 
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxLength; i++) {
		arr[i] = rand() % maxValue + 1;
	}


} 
void test(int testTime, int maxSize) {
	int maxValue = 100;
	int arr[maxSize];
	printf("测试次数为:%d,测试数组长度为:%d,测试数据如下:\n", testTime, maxSize);
	//归并排序
	clock_t start = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		process(arr, 0, maxSize - 1);
	}
	clock_t diff = clock() - start;

	printf( "归并排序耗时:%d ms\n", diff);
	//插入排序
	clock_t start1 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		insertSort(arr, maxSize);
	}
	clock_t diff1 = clock() - start1;

	printf( "插入排序耗时:%d ms\n", diff1);
	//快排
	clock_t start2 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		QuickSort_Recursion(arr, 0, maxSize - 1);
	}
	clock_t diff2 = clock() - start2;


	printf( "快排排序耗时:%d ms\n", diff2);
	//基数排序RadixCountSort
	clock_t start3 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		RadixCountSort(arr, maxSize, digit(maxValue));
	}
	clock_t diff3 = clock() - start3;


	printf( "基数排序耗时:%d ms\n", diff3);
	//计数排序RadixCountSort
	clock_t start4 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		CountSort(arr, maxSize, maxValue);
	}
	clock_t diff4 = clock() - start4;


	printf( "计数排序耗时:%d ms\n", diff4);
}
void insertSort(int *a, int n) {
	if (n == 0 || n < 2) {
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--) {
			swap(a, j, j + 1);
		}
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end) {
	int temp[end - begin + 1];
	int i = 0;
	int p1 = begin;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= end) {
		temp[i++] = a[p1] <= a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= mid) {
		temp[i++] = a[p1++];
	}
	while (p2 <= end) {
		temp[i++] = a[p2++];
	}
	for (i = 0; i < end - begin + 1; i++) {
		a[begin + i] = temp[i];
	}
}
void process(int *a, int begin, int end) {
	if (begin == end) {
		return;
	}
	int mid = begin + ((end - begin) >> 1);
	process(a, begin, mid);
	process(a, mid + 1, end);
	MergeArray(a, begin, mid, end);

}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end) {
	if (begin < end) {
		srand((unsigned)time(NULL));
		swap(a, begin + rand() % (end - begin + 1), end);
		int p[2];
		Partition(a, begin, end, p);
		QuickSort_Recursion(a, begin, p[0] - 1);
		QuickSort_Recursion(a, p[1] + 1, end);
	}
}
void Partition(int* a, int L, int R, int* b) {
	int less = L - 1;
	int more = R;
	while (L < more) {
		if (a[L] < a[R]) {
			swap(a, ++less, L++);
		} else if (a[L] > a[R]) {
			swap(a, --more, L);
		} else {
			L++;
		}
	}
	swap(a, more, R);
	b[0] = less + 1;
	b[1] = more;
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void init(int *a, int length) {
	for (int i = 0; i < length; i++) {
		a[i] = 0;
	}
}
void CountSort(int *a, int size, int max) {
	if (size < 2) {
		return;
	}
	int i, j, count, temp;
	int arr[max + 1];
	init(arr, max + 1);
	for (i = 0; i < size; i++) {
		arr[a[i]]++;
	}
	i = 0;
	for (int j = 0; j < max + 1; j++) {
		for (int k = 0; k < arr[j]; k++) {
			a[i++] = j;
		}
	}
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a, int size, int digit) {
	int i = 0, j = 0;
	int bucket[size];//准备辅助空间
	for (int d = 1; d <= digit; d++) { //看多少位

		int count[10] = {0}; //十进制 要记住初始化啊，不然寄
		for (i = 0; i < size; i++) {
			j = getDight(a[i], d);
			count[j]++;
		}
		for (i = 1; i < 10; i++) { //每个基数上的数代表d位上小于等于该索引号值的数的个数
			count[i] = count[i] + count[i - 1];
		}
		for (i = size - 1; i >= 0; i--) {
			j = getDight(a[i], d);
			bucket[count[j] - 1] = a[i];
			count[j]--;

		}
		for (i = 0, j = 0; i < size; i++, j++) {
			a[i] = bucket[j];
		}
	}
}
int getDight(int a, int d) { //得到数a第d位的值
	if (d == 1) {
		return a % 10;
	}
	a = a / ((d - 1) * 10);
	a %= 10;
	return a;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a, int size){
	int i=0,l=0;
	int r=size-1;
	for(i;i<=r;){
		if(a[i]==0){
			swap(a,l++,i++);
		}
		else if(a[i]==1){
			i++;
		}
		else{
			swap(a,i,r--);
		}
	}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int  getK(int *a,int k,int size){
	QuickSort_Recursion(a,0,size-1);
	return a[k-1];
} 

#endif // QUEUE_H_INCLUDED
