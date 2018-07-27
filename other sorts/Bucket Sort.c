//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//
//typedef struct node {
//	float data;
//	struct node *next;
//} NODE;
//
//typedef struct bucket {
//	int size;
//	struct node *list;
//} BUCKET;
//
//void bucketSort(float* A);
//void insertionSort(int *arraySort, int left, int right);
//int count;
//int main() {
//	int i;
//	float numbers;
//	float *BucketArray;
//	float gap = 0;
//	time_t startTime = 0, endTime = 0;
//	BucketArray = (float *)malloc(sizeof(float));
//	FILE *file;
//	file = fopen("bucket.txt", "r");				
//
//
//	if (file) {
//		while (fscanf(file, "%f", &numbers) > 0) {
//			*(BucketArray + count) = numbers;
//			count++;								
//			BucketArray = (float *)realloc(BucketArray, sizeof(float)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//	startTime = clock();
//	bucketSort(BucketArray);
//	endTime = clock();
//
//	printf("Bucket Sorted Array:");
//	puts("");
//	for (i = 0; i < count; i++)
//		printf("%-10f", BucketArray[i]);
//	puts("");
//	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
//	printf("\n원소의 개수가 %d개 일 때 : \n", count);
//	printf("탐색 시간 : %f 초 \n", gap);
//
//	free(BucketArray);
//	return 0;
//}
//