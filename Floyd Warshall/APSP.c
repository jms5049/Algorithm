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
