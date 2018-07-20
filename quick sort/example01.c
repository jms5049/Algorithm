//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//void quickSort(int *QuickArray, int p, int r);
//void swap(int *QuickArray, int one, int two);
//int partition(int *QuickArray, int p, int r);
//
//
//
//int main() {
//	int i,numbers, count = 0;
//	int *QuickArray;
//	QuickArray = (int *)malloc(sizeof(int) );
//	FILE *file;
//	file = fopen("test1.txt", "r");				
//	
//	if (file) {
//		while (fscanf(file, "%d", &numbers) > 0) {
//			*(QuickArray + count) = numbers;
//			count++;								
//			QuickArray = (int *)realloc(QuickArray, sizeof(int)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//
//
//	quickSort(QuickArray, 0 , count-1);
//
//	printf("Quicksorted Array: \n");	
//	for (i = 0; i < count; i++)
//		printf("%d\t", QuickArray[i]);
//
//	free(QuickArray);
//	return 0;
//}
//
//void quickSort(int *QuickArray, int p, int r) {
//	int q = 0;	
//
//	if (p < r) {
//		q = partition(QuickArray, p, r);
//		quickSort(QuickArray, p, q - 1);
//		quickSort(QuickArray, q + 1, r);
//	}
//}
//
//int partition(int *QuickArray, int p, int r) {
//	int x;
//	int i = 0;
//	int temp;
//
//
//	x = QuickArray[r];
//	i = p - 1;
//
//
//	for (int j = p; j < r; j++) {
//		if (QuickArray[j] <= x) {
//			i = i + 1;
//			swap(QuickArray,i, j);
//		}
//	}
//	swap(QuickArray,i + 1, r);
//
//	return i + 1;
//}
//
//void swap(int *QuickArray, int one, int two) {
//	int temp = 0;
//
//	temp = QuickArray[one];
//	QuickArray[one] = QuickArray[two];
//	QuickArray[two] = temp;
//}