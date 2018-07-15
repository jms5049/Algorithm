#include <stdio.h>

int arr[10000];
int size=0;
int i=0;

void insertionSort(int *A, int n) {
	int j,k,key = 0;
	size = sizeof(arr);
	size = size / 4;
	A[i] = n;
	
	
		for (k = 1; k < size; k++) {
			key = A[k];
			j = k - 1;
			if (key == NULL) {			
				break;
			}
			while (j >= 0 && A[j] > key) {
				A[j + 1] = A[j];
				j = j - 1;
			}
			j += 1;
			A[j] = key;
		}
	
	arr;
	i++;
}

void print() {
	int i = 0;
	size = sizeof(arr);
	size = size / 4;
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
		puts("");
	}
}

void main() {

	int score = 0;

	FILE *file;
	file = fopen("test_10000.txt", "r");					

	if (file) {
		while (fscanf(file, "%d", &score) > 0) {
			insertionSort(arr, score);				
		}
		print();								
		fclose(file);								
	}

}