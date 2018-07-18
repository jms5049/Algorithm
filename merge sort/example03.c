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



void mergeSort(int arraySort[], int left, int right)
{
	int mid;

	if ( ( (right - left) + 1 ) <= 8) {
		insertionSort(arraySort, left, right);
	}

	else if (left<right) {
		mid = (left + right) / 2;
		mergeSort(arraySort, left, mid);
		mergeSort(arraySort, mid + 1, right);
		merge(arraySort, left, mid, right);
	}

}

void merge(int arraySort[], int left, int mid, int right)
{
	
	int *array_left, *array_right;
	int n1, n2, i, j, k;

	n1 = mid - left + 1;
	array_left = (int*)malloc(sizeof(int)*n1);

	n2 = right - mid;
	array_right = (int*)malloc(sizeof(int)*n2);

	for (i = 0; i<n1; i++)
		array_left[i] = arraySort[left + i];

	for (j = 0; j<n2; j++)
		array_right[j] = arraySort[mid + j + 1];
	array_left[i] = INT_MAX;
	array_right[j] = INT_MAX;
	i = 0;
	j = 0;
	for (k = left; k <= right; k++) {
		if (array_left[i] <= array_right[j])
			arraySort[k] = array_left[i++];
		else
			arraySort[k] = array_right[j++];
	}

}
void insertionSort(int arraySort[], int left, int right) {
	int i, j;
	int temp = 0;

	for (i = 1; i <= right; i++) {
		temp = arraySort[i];
		for (j = i; j > 0; j--) {
			if (arraySort[j - 1] > temp) {
				arraySort[j] = arraySort[j - 1];
				if (j == 1) {
					arraySort[j - 1] = temp;
					break;
				}
			}
			else {
				arraySort[j] = temp;
				break;
			}
		}
	}

}
