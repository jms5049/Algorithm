#include<stdlib.h>
#include<stdio.h>

void merge(int arrayM[], int l, int m, int r);
void mergeSort(int arrayM[], int count);

int main()
{
	int *arrayM;
	int count = 0;
	int numbers, i;
	arrayM = (int *)malloc(sizeof(int));

	FILE *file;
	file = fopen("test_10000.txt", "r");				

	if (file) {
		while (fscanf(file, "%d", &numbers) > 0) {
			*(arrayM + count) = numbers;
			count++;								
			arrayM = (int *)realloc(arrayM, sizeof(int)*(count + 1));
		}
		fclose(file);								
	}

	mergeSort(arrayM, count);

	printf("Sorted Array:\n");
	for (i = 0; i < count; i++)
		printf("%d\n", arrayM[i]);

	return 0;
}

void mergeSort(int arrayM[], int count)
{
	int arraySize;		
	int leftHead;		

	for (arraySize = 1; arraySize <= count - 1; arraySize = 2 * arraySize)
	{
		
		for (leftHead = 0; leftHead<count - 1; leftHead = leftHead + 2 * arraySize)
		{
			int mid = leftHead + arraySize - 1;
			int rightTail = min(leftHead + 2 * arraySize - 1, count - 1);
			merge(arrayM, leftHead, mid, rightTail);
		}
	}
}
void merge(int arrayM[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *Larray;	
	int *Rarray;	
	Larray = (int *)malloc(sizeof(int) * n1);
	Rarray = (int *)malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		Larray[i] = arrayM[left + i];
	for (j = 0; j < n2; j++)
		Rarray[j] = arrayM[mid + 1 + j];

	i = 0;	
	j = 0;	
	k = left;

	for (i, j; i < n1 && j < n2;) {
		
		if (Larray[i] <= Rarray[j])
		{
			arrayM[k] = Larray[i];
			i++;
		}
		else
		{
			arrayM[k] = Rarray[j];
			j++;
		}
		k++;

	}

	for (i; i < n1; i++) {
		arrayM[k] = Larray[i];
		k++;
	}
	for (j; j < n2; j++){
		arrayM[k] = Rarray[j];
		k++;
	}

}
