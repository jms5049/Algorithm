#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct vertex {
	int index;
	int key;
	int parent;
} VERTEX;

typedef struct edge {
	int from;
	int to;
	int weight;
} EDGE;

void initGraph(int vertexNo);
void min_heapify(VERTEX *A, int i);
void min_heap_decrease_key(VERTEX *A, int x, int key);
void min_heap_insert(VERTEX *A, VERTEX key);
int parent(int i);
int left(int i);
int right(int i);
int heap_extract_min(VERTEX *A);
void relax(int u, int v, int w, VERTEX *A);
void initGraph(int vertexNo);
void printpath(VERTEX v);
void dijkstra(int **graph, EDGE* w, int root);

int **graph;
VERTEX *vertexes;
int heapSize;
int vertexNo;

int main() {
	int i, j, vi, vj, cost;
	int count = 0;
	EDGE *edges = (EDGE *)malloc(sizeof(EDGE));							
	FILE *file;
	file = fopen("graph_sample_dijkstra.txt", "r");						

	if (file) {
		fscanf(file, "%d", &vertexNo);									

		initGraph(vertexNo);											
		while (fscanf(file, "%d %d %d", &vi, &vj, &cost) > 0) {
			EDGE e;
			graph[vi][vj] = cost;										
			e.from = vi;												
			e.to = vj;
			e.weight = cost;
			edges[count] = e;
			count++;								
			edges = (int *)realloc(edges, sizeof(EDGE)*(count + 1));	
		}

		fclose(file);													
	}

	printf("\nDijkstra\n");
	printf("\nDirected Adjacent Matrix\n");
	for (i = 0; i < vertexNo; i++) {
		for (j = 0; j < vertexNo; j++) {
			printf("%-5d", graph[i][j]);
		}
		puts("");
	}
	puts("");

	dijkstra(graph, edges, 0);											//시작하고자 하는 루트를 정할수있다

	printf("Vertex           Cost        Path\n");
	for (i = 0; i < vertexNo; i++) {
			printf("%d\t\t %d\t %5d", vertexes[i].index, vertexes[i].key, vertexes[i].index);
			printpath(vertexes[i]);
			puts("");
	}
	puts("");

	return 0;
}
