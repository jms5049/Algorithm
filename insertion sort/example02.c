#include <stdio.h>

int arr[10000];
int size=0;
int i=0;

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