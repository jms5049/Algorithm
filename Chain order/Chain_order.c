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
//void matrixChainOrder(int* p) {
//	int **m = (int **)malloc(sizeof(int*)*matrixNo);
//	int **s = (int **)malloc(sizeof(int*)*matrixNo);
//	int i,j,k,l,q;
//
//	for (i = 0; i < matrixNo; i++) {
//		m[i] = (int *)malloc(sizeof(int) * matrixNo);
//		s[i] = (int *)malloc(sizeof(int) * matrixNo);
//	}
//
//	for (i = 0; i < matrixNo; i++) {
//		m[i][i] = 0;
//	}
//
//	for (l = 2; l <= matrixNo; l++) {
//		for (i = 0; i < matrixNo-l+1; i++) {
//			j = i + l - 1;
//			m[i][j] = INT_MAX;
//			for (k = i; k < j; k++) {
//				
//				q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
//				if (q < m[i][j]) {
//					m[i][j] = q;
//					s[i][j] = k;
//				}
//			}
//		}
//	}
//
//	puts("");
//	printOptimalParens(s, 0, matrixNo-1);
//	printf("\n\ncost: %d\n", m[0][matrixNo - 1]);
//}
//
