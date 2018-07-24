#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int randomizedSelect(int *QuickArray, int p, int r, int i);
void swap(int *QuickArray, int one, int two);
int partition(int *QuickArray, int p, int r);
int findmedian(int *A, int p, int r);
int veryMedianPivot(int *QuickArray, int p, int r);
void insertionSort(int *A, int p, int r);

int count;
int main() {
	int input = 0, output = 0;
	int i, numbers;
	int *numberArray;
	float gap = 0;
	time_t startTime = 0, endTime = 0;

	numberArray = (int *)malloc(sizeof(int));
	FILE *file;
	file = fopen("input10000.txt", "r");				


	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(numberArray + count) = numbers;
			count++;								
			numberArray = (int *)realloc(numberArray, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}

	printf("enter index to find i-th biggest number\n", input);
	scanf("%d", &input);

	if (input > count || input == 0) {
		printf("out of range error!\n");
		return 0;
	}
	startTime = clock();
	output = randomizedSelect(numberArray, 0, count - 1, input);
	endTime = clock();
	printf("output is %d \n", output);

	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	printf("\n원소의 개수가 %d개 일 때 : \n", count);
	printf("탐색 시간 : %f 초 \n", gap);

	return 0;
}
int randomizedSelect(int *A, int p, int r, int i) {
	int q = 0, k = 0;
	if (p == r)
		return A[p];
	q = veryMedianPivot(A, p, r);				
	k = q - p + 1;
	if (i == k)
		return A[q];
	if (i < k)
		return randomizedSelect(A, p, q - 1, i);
	else
		return randomizedSelect(A, q + 1, r, i - k);
}

