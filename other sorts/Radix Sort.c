//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//int bitMasking(int x, int k);
//void radixSort(int *A, int n);
//
//int main() {
//
//	int i, numbers,count=0;
//	int *CountArray;
//	float gap = 0;
//	time_t startTime = 0, endTime = 0;
//	CountArray = (int *)malloc(sizeof(int));
//	FILE *file;
//	file = fopen("input500.txt", "r");				
//	if (file) {
//		while (fscanf(file, "%d", &numbers) > 0) {
//			*(CountArray + count) = numbers;
//			count++;								
//			CountArray = (int *)realloc(CountArray, sizeof(int)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//	startTime = clock();
//	radixSort(CountArray, count);
//	endTime = clock();
//
//	printf("Radix Sorted :\n");
//	for (i = 0; i < count; i++)
//		printf("%-6d", CountArray[i]);
//
//	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
//	printf("\n원소의 개수가 %d개 일 때 : \n", count);
//	printf("탐색 시간 : %f 초 \n", gap);
//
//	return 0;
//}