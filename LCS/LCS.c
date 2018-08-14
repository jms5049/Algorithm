//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//#include <stdlib.h>
//
//int xLength;
//int yLength;
//void LCSlength(char *x, char *y);
//void printLCS(int **b, char *X, int i, int j);
//
//int main() {
//	int i = 0, j = 0;
//	char input;
//	char *x = (char *)malloc(sizeof(char));
//	char *y = (char *)malloc(sizeof(char));
//	FILE *file;
//	file = fopen("sample_lcs1.txt", "r");								// 파일 열기
//
//	if (file) {
//
//		fscanf(file, "%d", &xLength);									// x 읽어서 저장
//		x = (char *)realloc(x, sizeof(char) * (xLength+1));				
//		fgetc(file);
//		fgets(x, xLength + 1, file);
//
//		fscanf(file, "%d", &yLength);									// y 읽어서 저장
//		y = (char *)realloc(y, sizeof(char) * (yLength + 1));
//		fgetc(file);
//		fgets(y, yLength + 1, file);
//
//		fclose(file);													// 파일스트림 닫기
//	}
//
//	LCSlength(x, y);
//
//	return 0;
//
//}
//
//void LCSlength(char *x, char *y) {
//	int i,j;
//	int m = xLength;
//	int n = yLength;
//
//	int **b = (int **)malloc(sizeof(int*) * m+1);
//	int **c = (int **)malloc(sizeof(int*) * m+1);
//
//	for (i = 0; i < m+1; i++) {
//		b[i] = (int *)malloc(sizeof(int) * n+1);
//		c[i] = (int *)malloc(sizeof(int) * n+1);
//	}
//

//	for (i = 1; i < m+1; i++) {
//		c[i][0] = 0;
//	}
//
//	for (j = 0; j < n+1; j++) {
//		c[0][j] = 0;
//	}
//
//	for (i = 1; i < m+1; i++) {
//		for (j = 1; j < n+1; j++) {
//			if (x[i-1] == y[j-1]) {
//				c[i][j] = c[i - 1][j - 1] + 1;
//				b[i][j] = -1;					
//			}
//			else if(c[i-1][j]>=c[i][j-1]){
//				c[i][j] = c[i - 1][j];
//				b[i][j] = -2;					
//			}
//			else {
//				c[i][j] = c[i][j - 1];
//				b[i][j] = -3;					
//			}
//		}
//	}
//
//	printLCS(b, x, m, n);
//	puts("");
//}
//
