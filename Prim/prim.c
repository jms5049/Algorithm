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
