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

void initGraph(int vertexNo) {
	graph = (int **)malloc(sizeof(int*) * vertexNo);
	for (int i = 0; i < vertexNo; i++) {
		graph[i] = (int *)malloc(sizeof(int) * vertexNo);
	}
	for (int i = 0; i < vertexNo; i++) {
		for (int j = 0; j < vertexNo; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INT_MAX;
			}
		}
	}
}

int **floyd_Warshall(int **W) {
	int n;
	int **D = W;

	int **pastD;
	pastD = (int **)malloc(sizeof(int*) * vertexNo);
	for (int i = 0; i < vertexNo; i++) {
		pastD[i] = (int *)malloc(sizeof(int) * vertexNo);
	}

	printf("\nFloyd Warshall\n\n");
	printf("D(0)\n");
	printMatrix(D);

	for (int k = 1; k < vertexNo; k++) {
		pastD = D;
		for (int i = 1; i < vertexNo; i++) {
			for (int j = 1; j < vertexNo; j++) {
				if(pastD[i][k] != INT_MAX && pastD[k][j] != INT_MAX)
					D[i][j] = findmin(pastD[i][j], (pastD[i][k] + pastD[k][j]));
			}
		}
		printf("\nD(%d)\n", (k));
		printMatrix(D);
	}
	return D;
}

int findmin(int x, int y) {
	if (x <= y) {
		return x;
	}
	else {
		return y;
	}
}

void printMatrix(int **D) {
	for (int i = 0; i < vertexNo; i++) {
		for (int j = 0; j < vertexNo; j++) {
			if (D[i][j] == INT_MAX) {
				printf("¡Ä   ");
			}
			else {
				printf("%-5d", D[i][j]);
			}
		}
		puts("");
	}
}