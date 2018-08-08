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

void initGraph(int vertexNo) {
	//그래프 메모리 동적할당
	graph = (int **)malloc(sizeof(int*) * vertexNo);
	for (int i = 0; i < vertexNo; i++) {
		graph[i] = (int *)malloc(sizeof(int) * vertexNo);
	}
	//그래프의 모든 원소 0으로 초기화
	for (int i = 0; i < vertexNo; i++) {
		for (int j = 0; j < vertexNo; j++) {
			graph[i][j] = 0;
		}
	}
}

void min_heapify(VERTEX *A, int i) {
	int l, r, smallest;
	VERTEX temp ;

	l = left(i); //왼쪽 자식의 인덱스
	r = right(i); //오른쪽 자식의 인덱스
	if (l < heapSize && A[l].key < A[i].key)
		//왼쪽 자식이 존재하고, 왼쪽 자식이 그 부모보다 작을 때
		smallest = l;
	//smallest에 왼쪽 자식의 인덱스를 넣어준다.
	else
		smallest = i;

	if (r < heapSize && A[r].key < A[smallest].key)
		//오른쪽 자식이 존재하고, 위에서 찾은 최솟값보다 작으면
		smallest = r;
	//smallest에 오른쪽 자식의 인덱스를 넣어준다.

	if (smallest != i) {
		//smallest의 인덱스가 i가 아니면,
		//그 둘의 위치를 바꾸고,
		//smallest를 인자로 재귀 호출한다.
		temp = A[i];
		A[i] = A[smallest];
		A[smallest] = temp;

		min_heapify(A, smallest);
	}
}

int parent(int i) {
	//노드 i의 부모의 인덱스
	return floor(i / 2);
}

int left(int i) {
	//노드 i의 왼쪽 자식의 인덱스
	return 2 * i + 1;
}

int right(int i) {
	//노드 i의 오른쪽 자식의 인덱스
	return 2 * i + 2;
}

int heap_extract_min(VERTEX *A) {
	int min_value;

	min_value = A[0].index;
	A[0] = A[heapSize-1];
	//역시 min heap의 구조 특성상, 루트노드에 가장 작은 값이 들어있다.
	//따라서 루트 노드랑 리프노드의 맨 끝과 바꾸어 주면, 리프노드의 맨 끝에 가장 작은 값이 들어간다.
	heapSize--;
	//힙 구조에서 탈출 시키려면 힙 영역을 한칸 줄이자.
	//나중에 정렬된 배열에서도 이 수를 제외하기 위해, 정렬된 배열의 크기를 1만큼 줄인다.
	min_heapify(A, 0);
	//루트에는 이제, 원래 리프노드의 맨끝에 있던, 가장 큰 수중 하나가 들어간다.
	//루트노드에 대해 힙 구조를 다시 복구하자.
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
			//부모보다 작으면, 부모랑 자리를 바꾸자

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