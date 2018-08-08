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

	dijkstra(graph, edges, 0);											//�����ϰ��� �ϴ� ��Ʈ�� ���Ҽ��ִ�

	printf("Vertex           Cost        Path\n");
	for (i = 0; i < vertexNo; i++) {
			printf("%d\t\t %d\t %5d", vertexes[i].index, vertexes[i].key, vertexes[i].index);
			printpath(vertexes[i]);
			puts("");
	}
	puts("");

	return 0;
}

void initGraph(int vertexNo) {
	//�׷��� �޸� �����Ҵ�
	graph = (int **)malloc(sizeof(int*) * vertexNo);
	for (int i = 0; i < vertexNo; i++) {
		graph[i] = (int *)malloc(sizeof(int) * vertexNo);
	}
	//�׷����� ��� ���� 0���� �ʱ�ȭ
	for (int i = 0; i < vertexNo; i++) {
		for (int j = 0; j < vertexNo; j++) {
			graph[i][j] = 0;
		}
	}
}

void min_heapify(VERTEX *A, int i) {
	int l, r, smallest;
	VERTEX temp ;

	l = left(i); //���� �ڽ��� �ε���
	r = right(i); //������ �ڽ��� �ε���
	if (l < heapSize && A[l].key < A[i].key)
		//���� �ڽ��� �����ϰ�, ���� �ڽ��� �� �θ𺸴� ���� ��
		smallest = l;
	//smallest�� ���� �ڽ��� �ε����� �־��ش�.
	else
		smallest = i;

	if (r < heapSize && A[r].key < A[smallest].key)
		//������ �ڽ��� �����ϰ�, ������ ã�� �ּڰ����� ������
		smallest = r;
	//smallest�� ������ �ڽ��� �ε����� �־��ش�.

	if (smallest != i) {
		//smallest�� �ε����� i�� �ƴϸ�,
		//�� ���� ��ġ�� �ٲٰ�,
		//smallest�� ���ڷ� ��� ȣ���Ѵ�.
		temp = A[i];
		A[i] = A[smallest];
		A[smallest] = temp;

		min_heapify(A, smallest);
	}
}

int parent(int i) {
	//��� i�� �θ��� �ε���
	return floor(i / 2);
}

int left(int i) {
	//��� i�� ���� �ڽ��� �ε���
	return 2 * i + 1;
}

int right(int i) {
	//��� i�� ������ �ڽ��� �ε���
	return 2 * i + 2;
}

int heap_extract_min(VERTEX *A) {
	int min_value;

	min_value = A[0].index;
	A[0] = A[heapSize-1];
	//���� min heap�� ���� Ư����, ��Ʈ��忡 ���� ���� ���� ����ִ�.
	//���� ��Ʈ ���� ��������� �� ���� �ٲپ� �ָ�, ��������� �� ���� ���� ���� ���� ����.
	heapSize--;
	//�� �������� Ż�� ��Ű���� �� ������ ��ĭ ������.
	//���߿� ���ĵ� �迭������ �� ���� �����ϱ� ����, ���ĵ� �迭�� ũ�⸦ 1��ŭ ���δ�.
	min_heapify(A, 0);
	//��Ʈ���� ����, ���� ��������� �ǳ��� �ִ�, ���� ū ���� �ϳ��� ����.
	//��Ʈ��忡 ���� �� ������ �ٽ� ��������.
	return min_value;
}
void min_heap_decrease_key(VERTEX *A, int x, int key) {
	VERTEX temp;
	if (key > A[x].key) {
		printf("new key is bigger than current key");
	}
	else {
		A[x].key = key;
		while (x > 0 && A[parent(x)].key > A[x].key) {
			//�θ𺸴� ������, �θ�� �ڸ��� �ٲ���

			temp = A[x];
			A[x] = A[parent(x)];
			A[parent(x)] = temp;

			x = parent(x);
		}
	}
}

void min_heap_insert(VERTEX *A, VERTEX v) {
	A[heapSize++]=v;
	min_heap_decrease_key(A, heapSize-1, v.key);
}