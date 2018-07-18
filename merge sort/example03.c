#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

void mergeSort(int arraySort[], int left, int right);
void merge(int arraySort[], int left, int mid, int right);
void insertionSort(int arraySort[], int left, int right);

int main()
{
	int i, count = 0, numbers = 0;
	int *arraySort;
	float gap;
	time_t startTime = 0, endTime = 0;

	arraySort = (int*)malloc(sizeof(int));					

	FILE *file;
	file = fopen("test_10000.txt", "r");				

	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(arraySort + count) = numbers;
			count++;								
			arraySort = (int *)realloc(arraySort, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}

	mergeSort(arraySort, 0, count - 1);

	printf("Sorted Array:\n");
	for (i = 0; i < count; i++)
		printf("%d\n", arraySort[i]);

	free(arraySort);
	return 0;
}