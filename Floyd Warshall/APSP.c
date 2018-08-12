//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//void initGraph(int vertexNo);
//int **slow_All_Pairs_Shortest_Paths(int **W);
//int **faster_All_Pairs_Shortest_Paths(int **W);
//int **extend_Shortest_Paths(int **L, int **W);
//int findmin(int x, int y);
//void printMatrix(int **L);
//
//int **graph;
//int vertexNo;
//
//int main() {
//	int i, j, vi, vj, cost;
//	FILE *file;
//	file = fopen("graph_sample_directed.txt", "r");						
//
//	if (file) {
//		fscanf(file, "%d", &vertexNo);									
//
//		initGraph(vertexNo);											
//		while (fscanf(file, "%d %d %d", &vi, &vj, &cost) > 0) {
//			graph[vi][vj] = cost;										
//		}
//
//		fclose(file);													
//	}
//
//	slow_All_Pairs_Shortest_Paths(graph);
//	faster_All_Pairs_Shortest_Paths(graph);
//
//
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
//			if (i == j) {
//				graph[i][j] = 0;
//			}
//			else {
//				graph[i][j] = INT_MAX;
//			}
//		}
//	}
//}
//
//int **slow_All_Pairs_Shortest_Paths(int **W) {
//	int m;
//	int **L = W;
//	printf("\nSlow All-Pairs Shortest Paths and Matrix Multiplication\n\n");
//	printf("L(1)\n");
//	printMatrix(L);
//	for (m = 1; m < vertexNo-1; m++) {
//		L = extend_Shortest_Paths(L, W);
//		printf("\nL(%d)\n", (m+1));
//		printMatrix(L);
//	}
//	return L;
//}
//
//int **faster_All_Pairs_Shortest_Paths(int **W) {
//	int m=1;
//	int **L = W;
//	printf("\nFaster All-Pairs Shortest Paths and Matrix Multiplication\n\n");
//	printf("L(1)\n");
//	printMatrix(L);
//	while(m<vertexNo-1) {
//		L = extend_Shortest_Paths(L, L);
//		printf("\nL(%d)\n", (m*2));
//		printMatrix(L);
//		m *=2;
//	}
//	return L;
//}
//
//int **extend_Shortest_Paths(int **L, int **W) {
//	int **L2;
//	L2 = (int **)malloc(sizeof(int*) * vertexNo);
//	for (int i = 0; i < vertexNo; i++) {
//		L2[i] = (int *)malloc(sizeof(int) * vertexNo);
//	}
//
//	for (int i = 0; i < vertexNo; i++) {
//		for (int j = 0; j < vertexNo; j++) {
//			L2[i][j] = INT_MAX;
//			for (int k = 0; k < vertexNo; k++) {
//				if(L[i][k] != INT_MAX && W[k][j] !=INT_MAX)
//					L2[i][j] = findmin(L2[i][j], (L[i][k] + W[k][j]));
//			}
//		}
//	}
//	return L2;
//}
//
//int findmin(int x, int y) {
//	if (x <= y) {
//		return x;
//	}
//	else {
//		return y;
//	}
//}
//
//void printMatrix(int **L) {
//	for (int i = 0; i < vertexNo; i++) {
//		for (int j = 0; j < vertexNo; j++) {
//			if (L[i][j] == INT_MAX) {
//				printf("¡Ä   ");
//			}
//			else {
//				printf("%-5d", L[i][j]);
//			}
//		}
//		puts("");
//	}
//}