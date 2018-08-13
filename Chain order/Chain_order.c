//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//#include <stdlib.h>
//
//int matrixNo;
//void matrixChainOrder(int* p);
//void printOptimalParens(int** s, int i, int j);
//int main() {
//	int i = 0, j = 0, input;
//	int *p = (int *)malloc(sizeof(int));
//	FILE *file;
//	file = fopen("sample_mat1.txt", "r");								
//
//	if (file) {
//		fscanf(file, "%d", &matrixNo);									
//
//		p = (int *)realloc(p, sizeof(int) * (matrixNo+1));				
//		while (fscanf(file, "%d", &input) > 0) {
//			p[i++] = input;												
//		}
//
//		fclose(file);													
//	}
//
//	matrixChainOrder(p);
//
//	return 0;
//
//}
//