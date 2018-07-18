//#include<stdio.h>
//#include<stdlib.h>
//
//void swap(int *a, int *b);
//void bubblesort(int *arrayB, int count);
//
//int main() {
//	int *arrayB;
//	int count = 0;
//	int numbers, i;
//	arrayB = (int *)malloc(sizeof(int));
//
//	FILE *file;
//	file = fopen("test_10000.txt", "r");				
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
//	printf("Sorted Array:\n");
//	for (i = 0; i < count; i++)
//		printf("%d\n", arrayB[i]);
//	
//	return 0;
//
//}
//