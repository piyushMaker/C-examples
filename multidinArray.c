#include <stdio.h>

void passA(int (*rx)[2][3])
{
   int h, i, j;
    for(h = 0; h<2;h++){
    for(i = 0; i<2; i++)
     {
         for(j = 0; j<3; j++)
        {
            printf("%d,", *(*(*(rx + i) +j) +h));
        }
        printf("\n");
        
     }
     printf("\n");
    }
}

int array[2][2][3];// = {{1,2},{3,4},{5,6},
                     //   {11,22},{33,44},{55,66}};
int main()
{int h,i,j, d = 0;
     for(h = 0; h<2;h++){
    for(i = 0; i<2; i++)
     {
         for(j = 0; j<3; j++)
        {
            //array[h][i][j] = ++d ;
            *(*(*(array + i) +j) +h) =  ++d;
        }
        //printf("\n");
     }
    }
    
  passA(array);

    return 0;
}
