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
