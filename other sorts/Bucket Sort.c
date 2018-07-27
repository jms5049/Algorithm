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
//void bucketSort(float *A)
//{
//	NODE* node;
//	NODE* current;
//	BUCKET* bucket = (BUCKET*)malloc(sizeof(BUCKET)*count);
//	int bi = 0, temp = 0;
//
//	for (int i = 0; i < count; i++) {
//		bucket[i].size = 0;
//		bucket[i].list = NULL;
//	}
//
//	for (int i = 0; i<count; i++)
//	{
//		bi = count*A[i];
//
//		node = (NODE*)malloc(sizeof(NODE)*count);
//		node->data = A[i];
//		node->next = bucket[bi].list;
//		bucket[bi].list = node;
//		bucket[bi].size++;
//	}
//
//	for (int i = 0; i < count; i++) {
//		if (bucket[i].size == 0) {
//			continue;
//		}
//		else if (bucket[i].size == 1) {
//			A[temp++] = bucket[i].list->data;
//		}
//		else {
//			int begin = temp;
//			current = bucket[i].list;
//			while (current != NULL) {
//				A[temp++] = current->data;
//				current = current->next;
//			}
//			insertionSort(A, begin, temp - 1);
//		}
//	}
//}
//
//void insertionSort(int *arraySort, int left, int right) {
//	int i, j;
//	int temp = 0;
//
//	for (i = 1; i <= right; i++) {
//		temp = arraySort[i];
//		for (j = i; j > 0; j--) {
//			if (arraySort[j - 1] > temp) {
//				arraySort[j] = arraySort[j - 1];
//				if (j == 1) {
//					arraySort[j - 1] = temp;
//					break;
//				}
//			}
//			else {
//				arraySort[j] = temp;
//				break;
//			}
//		}
//	}
//
//}