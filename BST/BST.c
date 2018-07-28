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

