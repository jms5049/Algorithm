//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//
//
//typedef struct vertex {
//	int index;
//	int key;
//} VERTEX;
//
//void initGraph(int vertexNo);
//void prim(int **graph, int root);
//int parent(int i);
//int left(int i);
//int right(int i);
//void min_heapify(VERTEX *A, int i);
//int heap_extract_min(VERTEX *A);
//void min_heap_decrease_key(VERTEX *A, int x, int key);
//void min_heap_insert(VERTEX *A, VERTEX key);
//int find(VERTEX *A, int v);
//VERTEX getVertex(VERTEX *A, int v);
//
//int **graph;
//int heapSize;
//int vertexNo;
//
//int main() {
//	int i, j, vi, vj, cost;
//	int count = 0;
//	int tempRow = 0, tempCol = 0;
//	FILE *file;
//	file = fopen("graph.txt", "r");				
//
//	if (file) {
//		fscanf(file, "%d", &vertexNo);			
//
//		initGraph(vertexNo);
//		while (fscanf(file, "%d %d %d", &vi, &vj, &cost) > 0) {
//
//			graph[vi][vj] = cost;
//			graph[vj][vi] = cost;
//			count++;								
//		}
//
//		fclose(file);								
//	}
//
//	printf("adjacent matrix\n");
//	for (i = 0; i < vertexNo; i++) {
//		for (j = 0; j < vertexNo; j++) {
//			printf("%-3d", graph[i][j]);
//		}
//		puts("");
//	}
//	puts("");
//
//
//	prim(graph, 0);
//
//	free(graph);
//	return 0;
//}
//
//void initGraph(int vertexNo) {
//	graph = (int **)malloc(sizeof(int*) * vertexNo);
//	for (int i = 0; i < vertexNo; i++) {
//		graph[i] = (int *)malloc(sizeof(int) * vertexNo);
//	}
//	for (int i = 0; i < vertexNo; i++) {
//		for (int j = 0; j < vertexNo; j++) {
//			graph[i][j] = 0;
//		}
//	}
//}
//
//void prim(int **graph, int root) {
//	int *parent = (int *)malloc(sizeof(int)*vertexNo);
//	VERTEX *minheap = (VERTEX *)malloc(sizeof(VERTEX)*vertexNo);
//	VERTEX V;
//	int u, totalCost =0;
//	heapSize = 0;
//
//	for (int i = 0; i < vertexNo; i++) {
//		V.key = INT_MAX;
//		V.index = i;
//		parent[i] = -1;
//		min_heap_insert(minheap, V);
//	}
//	min_heap_decrease_key(minheap, root, 0);
//	while (heapSize > 0) {
//		u = heap_extract_min(minheap);			
//		for (int v = 0; v < vertexNo; v++) {
//			if (graph[u][v] > 0) {
//				if (find(minheap, v) != -1 && graph[u][v] < getVertex(minheap,v).key) {
//					parent[v] = u;					
//					min_heap_decrease_key(minheap, find(minheap, v), graph[u][v]);
//				}
//			}
//		}
//	}
//	printf("Prim\n");
//	printf("Path        Cost\n\n");
//	for (int i = 0; i < vertexNo; i++) {
//		if (parent[i] != -1) {
//			printf("%d   ->%4d%5d\n", parent[i], i, graph[parent[i]][i]);
//			totalCost += graph[parent[i]][i];
//		}
//	}
//	printf("\nTotal Cost = %d\n\n", totalCost);
//}
//
//int find(VERTEX *A, int v) {
//	for (int i = 0; i < heapSize; i++) {
//		if (v == A[i].index) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//VERTEX getVertex(VERTEX *A, int v) {
//	for (int i = 0; i < heapSize; i++) {
//		if (v == A[i].index) {
//			return A[i];
//		}
//	}
//	return;
//}
//
//void min_heapify(VERTEX *A, int i) {
//	int l, r, smallest;
//	VERTEX temp ;
//
//	l = left(i);
//	r = right(i);
//	if (l < heapSize && A[l].key < A[i].key)
//		smallest = l;
//	else
//		smallest = i;
//
//	if (r < heapSize && A[r].key < A[smallest].key)
//		smallest = r;
//
//	if (smallest != i) {
//		temp = A[i];
//		A[i] = A[smallest];
//		A[smallest] = temp;
//
//		min_heapify(A, smallest);
//	}
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
//int heap_extract_min(VERTEX *A) {
//	int min_value;
//
//	min_value = A[0].index;
//	A[0] = A[heapSize-1];
//	heapSize--;
//	min_heapify(A, 0);
//	return min_value;
//}
//
//void min_heap_decrease_key(VERTEX *A, int x, int key) {
//	VERTEX temp;
//	if (key > A[x].key) {
//		printf("new key is bigger than current key");
//	}
//	else {
//		A[x].key = key;
//		while (x > 0 && A[parent(x)].key > A[x].key) {
//
//			temp = A[x];
//			A[x] = A[parent(x)];
//			A[parent(x)] = temp;
//
//			x = parent(x);
//		}
//	}
//}
//
//void min_heap_insert(VERTEX *A, VERTEX v) {
//	A[heapSize++]=v;
//	min_heap_decrease_key(A, heapSize-1, v.key);
//}