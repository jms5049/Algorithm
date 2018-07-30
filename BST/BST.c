#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct TREENODE {
	int data;
	struct TREENODE *right;
	struct TREENODE *left;
	struct TREENODE *parent;
}TREENODE;

TREENODE* treeInsertRecursive(TREENODE *T, int z);
//TREENODE *treeInsertIterative(TREENODE *T, int z);
TREENODE *treeSearchRecursive(TREENODE *T, int k);
TREENODE *treeSearchIterative(TREENODE *T, int k);
TREENODE *treeSuccessor(TREENODE *T);
TREENODE *treePredecessor(TREENODE *T);
TREENODE *treeMin(TREENODE *T);
TREENODE *treeMax(TREENODE *T);
TREENODE* buildBST(TREENODE *T, int *A, int count);
void treeDelete(TREENODE *T, int z);
void transplant(TREENODE *T, TREENODE *u, TREENODE *v);
void printTree(TREENODE *T);
void insertionSort(int *A, int p, int r);
void swap(int *A, int p, int r);
int findmedian(int *A, int p, int r);

TREENODE *root;
int main() {
	int i, numbers,input,count=0;
	int *dataInput;
	dataInput = (int *)malloc(sizeof(int));
	FILE *file;
	file = fopen("µ¥ÀÌÅÍ.txt", "r");				

	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(dataInput + count) = numbers;
			count++;								
			dataInput = (int *)realloc(dataInput, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}


	TREENODE *BST = NULL;
	BST = buildBST(BST, dataInput, count);
	//printf("\nEnter the value to Delete in BST : ");
	//scanf("%d", &input);
	//treeSearchIterative(BST, input);			
	//treeDelete(BST, input);					
	puts("");
	//printTree(BST);							
	puts("");
	treeSuccessor(BST);
	treePredecessor(BST);
	puts("");


	return 0;
}
TREENODE* treeInsertRecursive(TREENODE *T, int z) {

	if (T == NULL)
	{
		root = (TREENODE *)malloc(sizeof(TREENODE));
		root->data = z;
		root->left = root->right = root->parent = NULL;
		return root;
	}
	
	if (z > (T->data))
	{
		T->right = treeInsertRecursive(T->right, z);
		T->right->parent = T;
	}
	else if (z < (T->data))
	{
		T->left = treeInsertRecursive(T->left, z);
		T->left->parent = T;
	}
	return T;
	
}

//TREENODE *treeInsertIterative(TREENODE *T, int z) {
//
//	if (T == NULL)
//	{
//		root = (TREENODE *)malloc(sizeof(TREENODE));
//		root->data = z;
//		root->left = root->right = root->parent = NULL;
//		return root;
//	}
//
//	else
//	{
//		while (1)
//		{	
//			if (T->data >= z && T->left == NULL)
//			{
//				TREENODE *temp;
//				temp = (TREENODE *)malloc(sizeof(TREENODE));
//				temp->data = z;
//				temp->left = temp->right = NULL;
//				temp->parent = T->left;
//				T->left = temp;
//				break;
//			}
//			else if (T->data >= z && T->left != NULL)
//			{
//				T = T->left;
//			}
//			else if (T->data< z && T->right == NULL)
//			{
//				TREENODE *temp;
//				temp = (TREENODE *)malloc(sizeof(TREENODE));
//				temp->data = z;
//				temp->left = temp->right = NULL;
//				temp->parent = T->right;
//				T->right = temp;
//				break;
//			}
//			else
//			{
//				T = T->right;
//			}
//		}
//		return root;
//	}
//}

TREENODE *buildBST(TREENODE *T, int *A, int count) {
	int i;

	printf("Insert without any sort\n");
	for (i = 0; i < count; i++) {
		T = treeInsertRecursive(T, A[i]);
		printTree(T, count);
		puts("");
	}
	return T;
}

TREENODE *treeSearchRecursive(TREENODE *T, int k) {
	if (T == NULL) {
		printf("Cannot Find Value %d in BST (RECURSIVE)\n", k);
		return 0;
	}
	if (k == T->data) {
		printf("Found Value %d in BST (RECURSIVE)\n", T->data);
		return T;
	}

	if (k < T->data)
		return treeSearchRecursive(T->left, k);
	else
		return treeSearchRecursive(T->right, k);
}

TREENODE *treeSearchIterative(TREENODE *T, int k) {
	while (T != NULL && k != T->data) {
		if (k < T->data)
			T = T->left;
		else
			T = T->right;
	}
	if (T == NULL) {
		printf("Cannot Find Value %d in BST (ITERATIVE)\n", k);
		return 0;
	}
	printf("Found Value %d in BST (ITERATIVE)\n", T->data);
	return T;
}
TREENODE *treeSuccessor(TREENODE *T) {
	TREENODE *y;
	y = (TREENODE *)malloc(sizeof(TREENODE));
	if (T->right != NULL)
		printf("Tree Successor = %d\n", treeMin(T->right)->data);
		return treeMin(T->right);

	y = T->parent;
	while ( y != NULL && T == y->right) {
		T = y;
		y = y->parent;
	}

	return y;
}


TREENODE *treePredecessor(TREENODE *T) {
	TREENODE *y;
	y = (TREENODE *)malloc(sizeof(TREENODE));
	if (T->left != NULL)
		printf("Tree Predecessor = %d\n", treeMax(T->left)->data);
		return treeMax(T->left);
	y = T->parent;
	while (y != NULL && T == y->left) {
		T = y;
		y = y->parent;
	}

	return y;
}

TREENODE *treeMin(TREENODE *T) {
	while (T->left != NULL)
		T = T->left;
	return T;
}
TREENODE *treeMax(TREENODE *T) {
	while (T->right != NULL)
		T = T->right;
	return T;
}

void printTree(TREENODE *T) {
	if (T == NULL) {
		return 0;
	}
	printTree(T->left);
	printf("%d ", T->data);
	printTree(T->right);
}


int findmedian(int *A, int p, int r) {
	int result;
	insertionSort(A, p, r);
	result = A[(int)ceil(p + (r - p) / 2)];
	A[p + (r - p) / 2] = 999999;
	swap(A, p + (r - p) / 2, r);
	return result;
}

void insertionSort(int *A, int p, int r) {
	int i = 0, j = 0, key = 0;
	for (i = p; i < r; i++) {
		key = A[i];
		j = i - 1;
		while ((j >= 0) && (A[j] > key)) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

void swap(int *A, int p, int r) {
	int temp = A[p];
	A[p] = A[r];
	A[r] = temp;
}
