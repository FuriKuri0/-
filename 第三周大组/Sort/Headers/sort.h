
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
void swap(int *a, int i, int j);//��������Ԫ�� 
int  getK(int *a,int k,int size);//�õ���K��С 
void test(int testTime, int maxSize);//���Ը�������ʱ�� 
void Partition(int* a, int L, int R, int* b);
void getBigRandArr(int* arr, int maxValue, int maxLength);//�õ�������� 
void insertSort(int *a, int n);//�������� 
//�鲢 
void MergeArray(int *a, int begin, int mid, int end);
void process(int *a, int begin, int end);
//���� 
void QuickSort_Recursion(int *a, int begin, int end);
//��ɫ 
void ColorSort(int *a, int size);
//���� 
void RadixCountSort(int *a, int size, int digit);
//���� 
void CountSort(int *a, int size, int max);
//��ӡ 
void printArr(int *a, int length);
//�õ�����a ��dλ�ϵ�ֵ������Ͱ���򣨻����� 
int getDight(int a, int d);
//����λ�� 
int digit(int a);
//�����ʼ�� 
void init(int *a, int length);
//����������鲢�����ļ� 
void save(int *arr, int maxValue, int maxLength);
//���ļ��еõ�������� 
void get(int *a,int maxLength);
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
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
//�������ݵ��ļ���
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
//���ļ��дӻ�ȡ����
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
//������Ϊ���������ұ����ļ��Ҵ��ļ��ж�ȡ�����еķ�ʽ���õ��漴���飬 
//������С���ݴ��������»����������ٶȣ��ʽ����ڴ�����С������ʹ�ã���ȡ��ע��
//ʹ��ʱ����getBigRandArrֻ����save��get���� 
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxLength; i++) {
		arr[i] = rand() % maxValue + 1;
	}


} 
void test(int testTime, int maxSize) {
	int maxValue = 100;
	int arr[maxSize];
	printf("���Դ���Ϊ:%d,�������鳤��Ϊ:%d,������������:\n", testTime, maxSize);
	//�鲢����
	clock_t start = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		process(arr, 0, maxSize - 1);
	}
	clock_t diff = clock() - start;

	printf( "�鲢�����ʱ:%d ms\n", diff);
	//��������
	clock_t start1 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		insertSort(arr, maxSize);
	}
	clock_t diff1 = clock() - start1;

	printf( "���������ʱ:%d ms\n", diff1);
	//����
	clock_t start2 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		QuickSort_Recursion(arr, 0, maxSize - 1);
	}
	clock_t diff2 = clock() - start2;


	printf( "���������ʱ:%d ms\n", diff2);
	//��������RadixCountSort
	clock_t start3 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		RadixCountSort(arr, maxSize, digit(maxValue));
	}
	clock_t diff3 = clock() - start3;


	printf( "���������ʱ:%d ms\n", diff3);
	//��������RadixCountSort
	clock_t start4 = clock();
	for (int i = 0; i < testTime; i++) {
		getBigRandArr(arr, maxValue, maxSize);
		CountSort(arr, maxSize, maxValue);
	}
	clock_t diff4 = clock() - start4;


	printf( "���������ʱ:%d ms\n", diff4);
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a, int size, int digit) {
	int i = 0, j = 0;
	int bucket[size];//׼�������ռ�
	for (int d = 1; d <= digit; d++) { //������λ

		int count[10] = {0}; //ʮ���� Ҫ��ס��ʼ��������Ȼ��
		for (i = 0; i < size; i++) {
			j = getDight(a[i], d);
			count[j]++;
		}
		for (i = 1; i < 10; i++) { //ÿ�������ϵ�������dλ��С�ڵ��ڸ�������ֵ�����ĸ���
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
int getDight(int a, int d) { //�õ���a��dλ��ֵ
	if (d == 1) {
		return a % 10;
	}
	a = a / ((d - 1) * 10);
	a %= 10;
	return a;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int  getK(int *a,int k,int size){
	QuickSort_Recursion(a,0,size-1);
	return a[k-1];
} 

#endif // QUEUE_H_INCLUDED
