#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int parent(int i);
int left(int i);
int right(int i);
void min_heapify(int *A, int i);
void build_min_heap(int *A);
int heap_extract_min(int *A);
void min_heapsort(int *A);
void min_heap_decrease_key(int *A, int x, int key);
void min_heap_insert(int *A, int key);
void min_heap_decrease_key_no_constraint(int *A, int x, int key);

int heap_size;
int count;

int main() {
	int *heap_array;
	int i, numbers;
	count = 0;

	heap_array = (int *)malloc(sizeof(int) * 10);
	FILE *file;
	file = fopen("test.txt", "r");				

	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(heap_array + count) = numbers;
			count++;								
			heap_array = (int *)realloc(heap_array, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}

	heap_size = count - 1;

	//min_heap_insert(heap_array, 77);				
	//printf("Heap Extract Min Result: %d \n", heap_extract_min(heap_array));		
	
	min_heapsort(heap_array, heap_size);			
	
	printf("Heap Sorted Array: \n");	for (i = 0; i < count; i++)
		printf("%d\n", heap_array[i]);

	free(heap_array);
	return 0;
}

int parent(int i) {
	return floor(i / 2);
}

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

