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
void relax(int u, int v, int w);
int bellmanford(int **graph, EDGE* w, int root);

void printpath(VERTEX v);
int **graph;
VERTEX *vertexes;
int vertexNo;
int count;

int main() {
	int i, j, vi, vj, cost;
	EDGE *edges = (EDGE *)malloc(sizeof(EDGE));							
	FILE *file;
	file = fopen("graph_sample_bellman.txt", "r");						

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

	printf("\nBellmanford\n");
	printf("\nDirected Adjacent Matrix\n");
	for (i = 0; i < vertexNo; i++) {
		for (j = 0; j < vertexNo; j++) {
			printf("%-5d", graph[i][j]);
		}
		puts("");
	}
	puts("");

	if (bellmanford(graph, edges, 0)) {									//사이클이 없어야 최단 경로니까
		printf("Vertex           Cost        Path\n");
		for (i = 0; i < vertexNo; i++) {
				printf("%d\t\t %d\t %5d", vertexes[i].index, vertexes[i].key, vertexes[i].index);
				printpath(vertexes[i]);
				puts("");
		}
		puts("");
	}

	return 0;
}

void initGraph(int vertexNo) {
	graph = (int **)malloc(sizeof(int*) * vertexNo);
	for (int i = 0; i < vertexNo; i++) {
		graph[i] = (int *)malloc(sizeof(int) * vertexNo);
	}
	for (int i = 0; i < vertexNo; i++) {
		for (int j = 0; j < vertexNo; j++) {
			graph[i][j] = 0;
		}
	}
}

int bellmanford(int **graph, EDGE* w, int root) {
	int i = 0, j = 0;

	//initialize single source s
	vertexes = (VERTEX *)malloc(sizeof(VERTEX));

	for (i = 0; i < vertexNo; i++) {
		VERTEX v;
		v.index = i;
		v.key = 9999;
		v.parent = -1;
		vertexes[i] = v;
	}
	vertexes[root].key = 0;

	//relax every edges
	for (i = 0; i < vertexNo; i++) {
		for (j = 0; j < count; j++) {
			relax(w[j].from, w[j].to, w[j].weight);
		}
	}
	puts("");

	free(graph);

	//test for solution
	for (i = 0; i < count; i++) {
		if (vertexes[w[i].to].key > vertexes[w[i].from].key + w[i].weight) {
			return 0;
		}
	}

	return 1;
}

void relax(int u, int v, int w) {
	if (vertexes[v].key > vertexes[u].key + w) {
		vertexes[v].key = vertexes[u].key + w;
		vertexes[v].parent = vertexes[u].index;
	}
}

void printpath(VERTEX v) {
	if (v.parent == -1) {
		return;
	}
	printf("<-%2d", v.parent);
	printpath(vertexes[v.parent]);
}