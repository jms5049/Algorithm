#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void mergeSort(int arrayM[], int left, int right);
void merge(int arrayM[], int left, int mid, int right);

int main()
{
	int i, count = 0, numbers = 0;
	int *arrayM;

	arrayM = (int*)malloc(sizeof(int));					

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

	mergeSort(arrayM, 0, count - 1);

	printf("Sorted Array:\n");
	for (i = 0; i < count; i++)
		printf("%d\n", arrayM[i]);

	free(arrayM);
	return 0;
}


void mergeSort(int arrayM[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;
		mergeSort(arrayM, left, mid);
		mergeSort(arrayM, mid + 1, right);
		merge(arrayM, left, mid, right);
	}

}

void merge(int arrayM[], int left, int mid, int right)
{
	int *array_left, *array_right;
	int n1, n2, i, j, k;

	n1 = mid - left + 1;
	array_left = (int*)malloc(sizeof(int)*n1);

	n2 = right - mid;
	array_right = (int*)malloc(sizeof(int)*n2);

	for (i = 0; i<n1; i++)
		array_left[i] = arrayM[left + i];

	for (j = 0; j<n2; j++)
		array_right[j] = arrayM[mid + j + 1];

	array_left[i] = INT_MAX;
	array_right[j] = INT_MAX;

	i = 0;
	j = 0;
	for (k = left; k <= right; k++) {
		if (array_left[i] <= array_right[j])
			arrayM[k] = array_left[i++];
		else
			arrayM[k] = array_right[j++];
	}
}