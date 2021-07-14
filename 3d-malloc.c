#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 3
#define ROWS 3
#define COLS 6

void passA(int ***rx)
{
   int height, row, cols;
    for(height = 0; height< HEIGHT; height++){
    for(row = 0; row< ROWS; row++)
     {
         for(cols = 0; cols< COLS; cols++)
        {
            printf("%d,", *(*(*(rx + height) + row) + cols));
        }
        printf("\n");
        
     }
     printf("\n");
    }
}

int ***array = NULL;
int main()
{
   int height,row, cols, data = 0;
   //Assigning Memory to Height
   array = (int***)malloc(sizeof(int**) * HEIGHT);
   for(height = 0; height< HEIGHT; height++)
   {  
	  //Assign Memory to Rows on each height
	  array[height] = (int **)malloc(sizeof(int*) * ROWS);
	  //Assign Memory to every Columns in each row at each height 
	   for(row = 0; row< ROWS; row++)
	   {
		   array[height][row] = (int *)malloc(sizeof(int) * COLS);
	   }
   }
   printf("Here \n");
   for(height = 0; height< HEIGHT;height++)
   {
    for(row = 0; row< ROWS; row++)
    {
     for(cols = 0; cols< COLS; cols++)
      {
         *(*(*(array + height) + row) + cols) =  ++data;
      }
    }
   }
   printf("Here2\n");
   passA(array);
   return 0;
}
