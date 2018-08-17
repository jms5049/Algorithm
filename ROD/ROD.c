//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//#include <stdlib.h>
//
//
//typedef struct rod {
//	int length;
//	int cost;
//}ROD;
//
//typedef struct pair {
//	int length;
//	int length2;
//}PAIR;
//
//int rodSize;
//PAIR pair;
//int cutRod(ROD* p, int n);
//int cutRodAux(ROD *p, int n, int *r);
//ROD* extendedBottomUpCutRod(ROD *p, int n);
//void printCutRodSolution(ROD *p, int n);
//int findmax(int x, int y);
//
//int main() {
//	int i = 0, length ,cost;
//	ROD *p = (ROD *)malloc(sizeof(ROD));
//	FILE *file;
//	file = fopen("rod_cutting.txt", "r");								
//
//	if (file) {
//		fscanf(file, "%d", &rodSize);									
//
//		p = (ROD *)realloc(p, sizeof(ROD) * (rodSize+1));				
//		while (fscanf(file, "%d %d", &length, &cost) > 0) {
//			p[i].length = length;
//			p[i].cost = cost;											
//			i++;
//		}
//
//		fclose(file);													
//	}
//
//	
//	cutRod(p, 5);
//	printCutRodSolution(p, 5);
//
//	return 0;
//}
//
//int cutRod(ROD *p, int n) {
//	int q;
//	printf("Recursive Cut Rod\n");
//	int *r = (int *)malloc(sizeof(int) * (n + 1));
//	for (int i = 0; i <= n; i++) {
//		r[i] = -INT_MAX;
//	}
//	
//	q = cutRodAux(p, n, r);
//	if (pair.length2 != 0) {
//		printf("Cutting Length : %d  %d\n", pair.length, pair.length2);
//		printf("Price : %d ( %d  %d )\n", q, r[pair.length], r[pair.length2]);
//	}
//	else {
//		printf("Cutting Length : %d\n", pair.length);
//		printf("Price : %d ( %d )\n", q, r[pair.length]);
//	}
//	return q;
//}
//
//int cutRodAux(ROD *p, int n, int *r) {
//	int q;
//	int length = 0, length2 = 0;
//
//	if (r[n] >= 0) {
//		return r[n];
//	}
//	if (n == 0)
//		q = 0;
//	else {
//		q = -INT_MAX;
//		for (int i = 1; i <= n; i++) {
//			if (q < findmax(q, p[i - 1].cost + cutRodAux(p, n - i, r))) {
//				q = findmax(q, p[i - 1].cost + cutRodAux(p, n - i, r));
//				length = i;
//				length2 = n - i;
//			}
//		}
//	}
//	r[n] = q;
//	pair.length = length;
//	pair.length2 = length2;
//	return q;
//}
//
//
//ROD* extendedBottomUpCutRod(ROD *p, int n) {
//	ROD *r = (ROD *)malloc(sizeof(ROD) * (n + 1));
//	int i, j, q;
//
//
//	r[0].cost = 0;
//	r[0].length = 0;
//
//	for (j = 1; j <= n; j++) {
//		q = -INT_MAX;
//		for (i = 1; i <= j; i++) {
//			if (q < p[i-1].cost + r[j - i].cost) {
//				q = p[i-1].cost + r[j - i].cost;
//				r[j].length = i;
//			}
//		}
//		r[j].cost = q;
//	}
//
//
//	return r;
//}
//
//void printCutRodSolution(ROD *p, int n) {
//	ROD *r = (ROD *)malloc(sizeof(ROD) * (n + 1));
//	int result[10];
//	int k = 0, temp = 0;
//	r = extendedBottomUpCutRod(p, n);
//
//	printf("Bottom Up Cut Rod\n");
//	printf("Cutting Length : ");
//	temp = n;
//	while (n > 0) {
//		printf("%d  ", r[n].length);
//		result[k] = r[r[n].length].cost;
//		n = n - r[n].length;
//		k++;
//	}
//
//	printf("\nPrice : %d (", r[temp].cost);
//	for (int i = 0; i < k; i++) {
//		printf(" %d ", result[i]);
//	}
//	printf(")\n");
//}
//
//int findmax(int x, int y) {
//	if (x >= y) {
//		return x;
//	}
//	else {
//		return y;
//	}
//}