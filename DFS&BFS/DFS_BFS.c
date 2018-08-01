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


void bfs(int **graph, int vertex) {
	int *visitBFS = (int*)malloc(sizeof(int*) * vertexNo);
	int i = 0, j = 0;
	initQueue();
	init(visitBFS);

	visitBFS[vertex] = 1;	
	addQueue(vertex);
	printf("BFS on ROOT : %d \n" , vertex);	
	
	while (!isEmpty()) {
		i = peekQueue();
		printf("%-3d->  ", removeQueue());
		for (j = 0; j < vertexNo; j++) {
			if (graph[i][j]) {
				while (visitBFS[j] == 0) {
					visitBFS[j] = 1;
					addQueue(j);
				}
			}
		}
	}
}


void addQueue(int i) {
	if ((rear + 1) % vertexNo == front) {
		printf("Queue Overflow \n");
		return -1;
	}
	queue[rear] = i;
	rear = ++rear % vertexNo;
}

int removeQueue() {
	int i;
	if (front == rear) {
		printf("Queue Empty\n");
		return -1;
	}
	i = queue[front];
	front = ++front % vertexNo;
	return i;
}

int isEmpty() {
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int peekQueue() {
	return queue[front];
}

void initQueue() {
	front = rear = 0;
}

int init(int *A) {
	for (int i = 0; i < vertexNo; i++) {
		A[i] = 0;
	}
}