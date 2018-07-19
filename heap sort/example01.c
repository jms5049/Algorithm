//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//int parent(int i);
//int left(int i);
//int right(int i);
//void max_heapify(int *A, int i);
//void build_max_heap(int *A);
//int heap_extract_max(int *A);
//void max_heapsort(int *A);
//void max_heap_increase_key(int *A, int x, int key);
//void max_heap_insert(int *A, int key);
//void max_heap_increase_key_no_constraint(int *A, int x, int key);
//
//int heap_size;
//int count;
//
//int main() {
//	int *heap_array;
//	int i,numbers;
//	count = 0;
//	heap_array = (int *)malloc(sizeof(int) );
//	FILE *file;
//	file = fopen("test.txt", "r");				
//	
//	if (file) {
//		while (fscanf(file, "%d", &numbers) > 0) {
//			*(heap_array + count) = numbers;
//			count++;								
//			heap_array = (int *)realloc(heap_array, sizeof(int)*(count + 1));
//		}
//		fclose(file);								
//	}
//
//	heap_size = count - 1;
//	
//
//	max_heap_insert(heap_array, 77);				
//	//printf("Heap Extract Max Result: %d \n", heap_extract_max(heap_array));		
//	max_heapsort(heap_array, heap_size);
//
//
//
//	//Ãâ·Â
//	printf("Heapsorted Array: \n");	for (i = 0; i < count; i++)
//		printf("%d\n", heap_array[i]);
//
//	free(heap_array);
//	return 0;
//}
//
//int parent(int i) {
//	return floor(i / 2);
//}
//
//int left(int i) {
//	return 2 * i + 1;
//}
//
//int right(int i) {
//	return 2 * i + 2;
//}
//