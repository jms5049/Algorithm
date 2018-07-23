//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//
//void countingSort(int *A, int *B, int k);
//int findDegree(int *A, int k);
//int findMax(int *A, int k);
//int findMin(int *A, int k);
//int degree;
//int count;
//int main() {
//	int i, numbers;
//	int *sorted;
//	int *CountArray;
//	float gap = 0;
//	time_t startTime = 0, endTime = 0;
//	CountArray = (int *)malloc(sizeof(int));
//	FILE *file;
//	file = fopen("counting.txt", "r");				
//
//
//	if (file) {
//		while (fscanf(file, "%d", &numbers) > 0) {
//			*(CountArray + count) = numbers;
//			count++;								
//			CountArray = (int *)realloc(CountArray, sizeof(int)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//	sorted = (int *)malloc(sizeof(int)*count);
//
//
//	degree = findDegree(CountArray, count-1);
//	startTime = clock();
//	countingSort(CountArray, sorted, degree+1);
//	endTime = clock();
//
//	printf("Counting Sorted Array:");
//	puts("");
//	for (i = 0; i < count; i++)
//		printf("%-4d", sorted[i]);
//	puts("");
//	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
//	printf("\n원소의 개수가 %d개 일 때 : \n", count);
//	printf("탐색 시간 : %f 초 \n", gap);
//	free(CountArray);
//	return 0;
//}
//
//void countingSort(int *A, int *B, int k) {
//	int i = 0;
//	int j = 0;
//	int *C = (int *)malloc(sizeof(int)*(degree));
//
//	for (i=0; i < k; i++) {
//		*(C + i) = 0;
//	}
//
//	for (j = 0; j < count; j++) {
//		*(C + (A[j])) += 1;
//	}
//
//	for (i = 0; i < k; i++) {
//		printf("%d 의 개수 %d\n", i,*(C + i));
//	}
//	puts("");
//	
//	for (i = 1; i < k; i++) {
//		*(C + i) = *(C + i) + *(C + (i - 1));
//	}
//
//	for (j = count-1; j > -1; j--) {
//		B[*(C + A[j])-1] = A[j];
//		*(C + A[j]) -= 1;
//	}
//}
//
//int findDegree(int *A, int k) {
//	int result = 0;
//	result = (findMax(A, k) - findMin(A, k));
//	if (result < 0)
//		//에러
//		return 0;
//	else
//		printf("수의 범위 :%d\n", result);
//		puts("");
//		return result;
//}
//
//int findMax(int *A, int k) {
//	int i;
//	//int * temp= (int *)malloc(sizeof(int)*k);;
//	for (i = 1; i < k; ++i)
//	{
//		if (A[0] < A[i])
//			A[0] = A[i];
//	}
//	i = A[0];
//	return i;
//}
//
//int findMin(int *A, int k) {
//	int i;
//	for (i = 1; i < k; ++i)
//	{
//		if (A[0] > A[i])
//			A[0] = A[i];
//	}
//	i = A[0];
//	return i;
//}