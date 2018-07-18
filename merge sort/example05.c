//#include<stdio.h>
//#include<stdlib.h>
//
//void swap(int *a, int *b);
//void bubblesort(int *arrayB, int count);
//void find(int wanted);
//void binarySearch(int *arrayB, int wanted, int left, int right);
//int *arrayB;
//int count = 0;
//
//int main() {
//	int numbers, i;
//	arrayB = (int *)malloc(sizeof(int));
//
//	FILE *file;
//	file = fopen("test_recursive.txt", "r");				
//
//	if (file) {
//		while (fscanf(file, "%d", &numbers) > 0) {
//			*(arrayB + count) = numbers;
//			count++;								
//			arrayB = (int *)realloc(arrayB, sizeof(int)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//	bubblesort(arrayB, count);
//	
//	printf("Sorted Array: \n");
//	for (i = 0; i < count; i++)
//		printf("%d\n", arrayB[i]);
//	
//	find(689);
//
//	return 0;
//
//}
//void find(int wanted) {
//
//	binarySearch(arrayB, wanted, 0, count);
//
//}
//
//void binarySearch(int *arrayB, int wanted, int left, int right) {
//
//	int mid = (left + right) / 2;
//
//	if (mid == left) {
//		printf("배열에 해당 원소는 없습니다.\n");
//		return 0;
//	}
//
//	if (wanted == arrayB[mid]) {
//		printf(">>>>>%d 는 배열의 %d 째 인덱스에 존재합니다<<<<<\n",arrayB[mid], mid);
//		return 0;
//	}
//	else if (wanted > arrayB[mid]) {
//		binarySearch(arrayB, wanted, mid, right);
//	}
//	else{
//		binarySearch(arrayB, wanted, left, mid);
//	}
//
//}
//
//void swap(int *a, int *b) {
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void bubblesort(int *arrayB, int count) {
//	for (int i = count; i > 0; i--)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (arrayB[j-1] > arrayB[j])
//				swap(&arrayB[j], &arrayB[j - 1]);
//		}
//	}
//}