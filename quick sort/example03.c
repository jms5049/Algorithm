#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define subarraySize 9

//void quickSort(int *QuickArray, int p, int r);
void complexSort(int *QuickArray, int p, int r);
void swap(int *QuickArray, int one, int two);
int partition(int *QuickArray, int p, int r);
void insertionSort(int *arraySort, int left, int right);

int *QuickArray;
int main() {
	int i, numbers, count = 0;
	float gap = 0;
	time_t startTime = 0, endTime = 0;
	QuickArray = (int *)malloc(sizeof(int));
	FILE *file;
	file = fopen("test1.txt", "r");


	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(QuickArray + count) = numbers;
			count++;								
			QuickArray = (int *)realloc(QuickArray, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}
	
	startTime = clock();
	complexSort(QuickArray, 0, count - 1);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	printf("Quicksorted Array: \n");
	for (i = 0; i < count; i++)
		printf("%d\n", QuickArray[i]);

	printf("삽입 정렬하는 배열의 크기 : %d 개 일때\n", subarraySize);
	printf("정렬 시간 : %f 초 \n", gap);
	free(QuickArray);
	return 0;
}

void complexSort(int *QuickArray, int p, int r) {
	int q = 0;	
	if (p < r) {
		
		if ((r - q) < subarraySize) {
			insertionSort(QuickArray, p, r);
		}

		else {
			q = partition(QuickArray, p, r);
			complexSort(QuickArray, p, q - 1);
			complexSort(QuickArray, q + 1, r);
		}
	}
}

int partition(int *QuickArray, int p, int r) {
	int x;
	int i = 0;
	int temp;

	x = QuickArray[r];

	i = p - 1;

	for (int j = p; j < r; j++) {
		if (QuickArray[j] <= x) {
			i = i + 1;
			swap(QuickArray, i, j);
		}
	}
	swap(QuickArray, i + 1, r);

	return i + 1;
}

void swap(int *QuickArray, int one, int two) {
	int temp = 0;

	temp = QuickArray[one];
	QuickArray[one] = QuickArray[two];
	QuickArray[two] = temp;
}

void insertionSort(int *arraySort, int left, int right) {
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