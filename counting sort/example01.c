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