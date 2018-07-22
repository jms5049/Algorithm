//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//void quickSort(int *QuickArray, int p, int r);
//void swap(int *QuickArray,int one, int two);
//int partition(int *QuickArray, int p, int r);
//int random(int *QuickArray, int p, int r);
//int median(int a, int b, int c);
//
//int main() {
//	int one = 0;
//	int two = 0;
//	int i, numbers, count = 0;
//	int *QuickArray;
//	QuickArray = (int *)malloc(sizeof(int));
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
//void quickSort(int *QuickArray, int p, int r) {
//	int q = 0;
//
//	if (p < r) {
//		q = random(QuickArray, p, r);
//		quickSort(QuickArray, p, q - 1);
//		quickSort(QuickArray, q + 1, r);
//	}
//}
//
//int random(int *QuickArray, int p, int r) {
//	int a = 0, b = 0, c = 0, i = 0;
//
//	a = p + ( rand() % (r - p + 1) );
//	a = QuickArray[a];
//	b = p + ( rand() % (r - p + 1) );
//	b = QuickArray[b];
//	c = p + ( rand() % (r - p + 1) );
//	c = QuickArray[c];
//	
//	i = median(a, b, c);
//
//	swap(QuickArray,i, r);
//
//	return partition(QuickArray, p, r);
//}
//
//int median(int a, int b, int c) {
//
//	int x = a - b;
//	int y = b - c;
//	int z = a - c;
//	if (x*y > 0) return b;
//	if (x*z > 0) return c;
//	return a;
//
//}
//