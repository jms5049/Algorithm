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