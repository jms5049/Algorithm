//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//#include <float.h>
//#include <stdlib.h>
//
//void OBST(float *p, float *q, int n);
//
//int main() {
//
//	int i = 0;
//	int size;
//	float prob;
//	float *p = (float *)malloc(sizeof(float));
//	float *q = (float *)malloc(sizeof(float));
//	FILE *file;
//	file = fopen("OBST-2.txt", "r");									// ���� ����
//
//	if (file) {
//		fscanf(file, "%d", &size);										// �� ù���� �о ����� ũ�� �˱�
//
//		p = (float *)realloc(p, sizeof(float) * (size + 2));			
//
//		i = 1;
//		while (fscanf(file, "%f", &prob) > 0) {							// k�� ã�� Ȯ���� ���� p ���� �� �� ����
//			p[i++] = prob;
//			if (i > size) {
//				break;
//			}
//		}
//
//		i = 0;
//		while (fscanf(file, "%f", &prob) > 0) {							// d�� Ž���� Ȯ���� ���� q ���� �� �� ����
//			q[i++] = prob;
//		}
//
//		fclose(file);													// ���Ͻ�Ʈ�� �ݱ�
//	}
//
//	OBST(p, q, size);
//
//	return 0;
//}
//
//void OBST(float *p, float *q, int n) {
//	int i, j, l, r;
//	float t;
//	float **e = (float **)malloc(sizeof(float*) * n + 1);
//	float **w = (float **)malloc(sizeof(float*) * n + 1);
//	int **root = (int **)malloc(sizeof(int*) * n + 1);
//	
//	for (i = 1; i <= n + 1; i++) {
//		e[i] = (float *)malloc(sizeof(float) * n + 1);
//		w[i] = (float *)malloc(sizeof(float) * n + 1);
//	}
//	for (i = 1; i <= n; i++) {
//		root[i] = (int *)malloc(sizeof(int) * n + 1);
//	}
//	for (i = 1; i <= n+1; i++) {
//		e[i][i-1] = q[i-1];
//		w[i][i-1] = q[i-1];
//	}
//	
//	for (l = 1; l <= n; l++) {
//		for (i = 1; i <= n - l+1; i++) {
//			j = i + l - 1;
//			e[i][j] = FLT_MAX;
//			w[i][j] = w[i][j - 1] + p[j] + q[j];
//			for (r = i; r <= j; r++) {
//				t = e[i][r-1] + e[r+1][j] + w[i][j];
//				if (t < e[i][j]) {
//					e[i][j] = t;
//					root[i][j] = r;
//				}
//			}
//		}
//	}
//
//	
//}
