//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//void quickSort(int *QuickArray, int p, int r);
//void swap(int *QuickArray,int one, int two);
//int partition(int *QuickArray, int p, int r);
//int random(int *QuickArray, int p, int r);
//
//
//
//int main() {
//	int i, numbers, count = 0;
//	int *QuickArray;
//	QuickArray = (int *)malloc(sizeof(int));
//	FILE *file;
//	file = fopen("test2.txt", "r");				
//
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
//	quickSort(QuickArray, 0, count - 1);
//
//
//	printf("Quicksorted Array: \n");
//	for (i = 0; i < count; i++)
//		printf("%d\n", QuickArray[i]);
//
//	free(QuickArray);
//	return 0;
//}
//