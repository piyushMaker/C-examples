/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int n = 100;
typedef struct triangle{
    int data;
    int index;
} triangle;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void arraySort(triangle *arr[], int n)
{
      int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j]->data > arr[j+1]->data)
              swap(&arr[j], &arr[j+1]);
    
}
int main()
{
    //int n = 10;
    triangle *srray[n], area[n];
    for (int a = 0; a < n; a++)
    {
        srray[a] = &area[a];
    }
    for (int a = 0; a < n; a++)
    {
        //printf("Hello Worl2");
        srray[a]->data = (rand() % (30 - 65 + 1)) + 30;
        srray[a]->index = a;
    }
    
    // for (int a = 0; a < n; a++)
    // {
    //     printf("%d ", srray[a]->data);
    //     printf("%d\t", srray[a]->index);
    // }
    
    arraySort(srray, n);
    printf("\n");
    for (int a = 0; a < n; a++)
    {
        printf("%d ", srray[a]->data);
        printf("Index: %d\n", srray[a]->index);
    }
    
    return 0;
}
