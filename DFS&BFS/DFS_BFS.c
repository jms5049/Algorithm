#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void bfs(int **graph, int vertex);
void dfs(int **graph, int vertex);
void initQueue();
void addQueue(int i);
int removeQueue();
int isEmpty();

int **graph;
int *queue;
int *visitDFS;
int vertexNo;
int front = 0, rear = 0;

int main() {
	int i,j,numbers;
	int count = 0;
	int tempRow = 0, tempCol = 0;
	FILE *file;
	file = fopen("graph.txt", "r");				

	if (file) {
		fscanf(file, "%d", &vertexNo);			

		graph = (int **)malloc( sizeof(int*) * vertexNo);
		for (i = 0; i < vertexNo; i++) {
			graph[i] = (int *)malloc( sizeof(int) * vertexNo);
		}

		while (fscanf(file, "%d", &numbers) > 0) {
			tempRow = count / vertexNo;				
			tempCol = count % vertexNo;				
			graph[tempRow][tempCol] = numbers;
			count++;								
		}
		
		fclose(file);								
	}

	queue = (int*)malloc(sizeof(int*) * vertexNo);

	visitDFS = (int*)malloc(sizeof(int*) * vertexNo);
	init(visitDFS);	
	printf("\nDFS on ROOT : 0\n0  ->  ");
	dfs(graph, 0);
	printf("End of Graph \n\n");
	
	bfs(graph, 0);
	printf("End of Graph \n\n");

	free(graph);
	return 0;
}
