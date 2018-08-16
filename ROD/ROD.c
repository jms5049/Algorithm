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
