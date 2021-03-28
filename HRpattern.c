#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n, sizeSq;
    scanf("%d", &n);
    sizeSq = (2 * n) - 1;
    printf("sizeSq = %d\n", sizeSq);
    int **arr = (int**)malloc(sizeSq * sizeof(int*));
      	// Complete the code to print the patten.
    for(int itr = 0; itr < sizeSq; itr++)
    {
        arr[itr] = (int *)calloc(sizeSq, sizeof(int));
    } 
    //2d array ready.
    //for val 2
    //222,212,222
    
   for(int outl = n; outl > 0; outl--)
    {
        static int ptrR = 0, ptrC = 0;
        int sizemMax = ((2 * outl) -1); //3, 2 
        
        for(int arrR = 0; arrR < sizemMax; arrR++)
        {
            
           for(int arrC = 0; arrC < sizemMax; arrC++)
           {
               if(arrR == 0 || arrR == (sizemMax - 1))
                    {
                        *(arr[ptrR +arrR] + (ptrC + arrC)) = outl;
                        
                    }
                else{
                        if(arrC == 0 || arrC == (sizemMax-1))
                        {
                            *(arr[ptrR + arrR] + (ptrC + arrC)) = n;
                        
                        }
                    }
           }
        }
         ptrC +=1;
         ptrR +=1;  
    } 
        
        for(int j = 0; j < sizeSq; j++)
        {
            for(int k = 0; k < sizeSq; k++)
            {
                printf("%d ", *(arr[j]+k));
            }
            printf("\n");
        }      
        
    return 0;
}