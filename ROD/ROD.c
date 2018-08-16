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
