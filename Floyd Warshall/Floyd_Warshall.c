#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void initGraph(int vertexNo);
int **floyd_Warshall(int **W);
int findmin(int x, int y);
void printMatrix(int **L);

int **graph;
int vertexNo;

int main() {
	int i, j, vi, vj, cost;
	FILE *file;
	file = fopen("graph_sample_directed.txt", "r");						
	if (file) {
		fscanf(file, "%d", &vertexNo);									

		initGraph(vertexNo);											
		while (fscanf(file, "%d %d %d", &vi, &vj, &cost) > 0) {
			graph[vi][vj] = cost;										
		}

		fclose(file);													
	}

	floyd_Warshall(graph);


	return 0;
}
