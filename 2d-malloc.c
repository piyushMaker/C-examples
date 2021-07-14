#include <stdio.h>
#include <stdlib.h>
int row = 2;
int col = 3;
int data = 0;

void printArr(int **rxarr)
{
	for(int j = 0; j < row; j++)
	{
		for(int k = 0; k< col; k++)
		{
			printf("Address: %p\t value: %d\n", rxarr[j] + k, *(rxarr[j] + k));
		}
		//printf("\n");
	}
}
int main()
{
	int **array = NULL;
	
	//Malloc in Rows disection
	array = (int**)malloc(sizeof(int *) * row);
	//Malloc in Coloums direction
	for(int i = 0; i < col; i++)
	{
		array[i] = (int*)malloc(sizeof(int) *col);
	}
	//Fill in data
	for(int j = 0; j < row; j++)
	{
		for(int k = 0; k< col; k++)
		{
		  *(array[j] + k) = ++data;	
		}
		//printf("\n");
	}
	
	printArr(array);
	
return 0;
}