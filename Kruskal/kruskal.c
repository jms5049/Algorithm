//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//
//typedef struct edge {
//	int from;
//	int to;
//	int weight;
//} EDGE;
//
//void initGraph(int vertexNo);
//int findSet(int* parent, int i);
//void unionSet(int *parent, int i, int j);
//void sortEdge(EDGE *E);
//void kruskal(int **G, EDGE *w);
//
//int **graph;
//int heapSize;
//int vertexNo;
//int count;
//int main() {
//	int i, j, vi, vj, cost;
//	int tempRow = 0, tempCol = 0;
//	FILE *file;
//	EDGE *edges = (EDGE *)malloc(sizeof(EDGE));
//	EDGE e;
//	file = fopen("graph.txt", "r");				
//
//	if (file) {
//		fscanf(file, "%d", &vertexNo);			
//		initGraph(vertexNo);
//
//		while (fscanf(file, "%d %d %d", &vi, &vj, &cost) > 0) {
//			e.from = vi;
//			e.to = vj;
//			e.weight = cost;
//			edges[count] = e;
//			graph[vi][vj] = cost;
//			graph[vj][vi] = cost;
//			count++;								
//			edges = (int *)realloc(edges, sizeof(EDGE)*(count + 1));
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
//	kruskal(graph, edges);
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
