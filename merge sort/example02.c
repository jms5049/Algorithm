#include<stdlib.h>
#include<stdio.h>

void merge(int arrayM[], int l, int m, int r);
void mergeSort(int arrayM[], int count);

int main()
{
	int *arrayM;
	int count = 0;
	int numbers, i;
	arrayM = (int *)malloc(sizeof(int));

	FILE *file;
	file = fopen("test_10000.txt", "r");				

	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(arrayM + count) = numbers;
			count++;								
			arrayM = (int *)realloc(arrayM, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}

	mergeSort(arrayM, count);

	printf("Sorted Array:\n");
	for (i = 0; i < count; i++)
		printf("%d\n", arrayM[i]);

	return 0;
}