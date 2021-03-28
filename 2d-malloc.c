#include <stdio.h>
#include <stdlib.h>

int row = 2;
int col = 3;
int data = 0;

void printArr(int **rxarr)
{
	for(int j = 0; j< row; j++)
	{
		for(int k = 0; k< col; k++)
		{
			printf("Addr %p\t", (rxarr[j]+k));
			printf("Value %d\n", *(rxarr[j]+k));
		}
	}	
}
int main()
{
	int **array = NULL;
	array = (int **)malloc(sizeof(int*) * row);
	for(int i = 0 ; i< col; i++)
	{
	  //  printf("value added");
		array[i] = (int *)malloc(sizeof(int) * col);
	}
	
	//Fill Array
	for(int j = 0; j< row; j++)
	{
		for(int k = 0; k< col; k++)
		{
		  //  printf("value added2\n");
			*(array[j] + k) = ++data;
		}
	}
	printArr(array);
}