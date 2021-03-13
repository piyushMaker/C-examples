#include <stdio.h>

void multiptr(int ***arg)
{
        printf("%d\n",***arg);
}

//char array[2][3] = {1,2,3,4,5,6};
int main()
{
    int base = 5;
    int *ptr1;
    int **ptr2;
    int ***ptr3;
    
    ptr1 = &base;
    //ptr1 = base;
    ptr2 = &ptr1;
    ptr3 = &ptr2;
    
    multiptr(ptr3);
    //printf("Hello World");

    return 0;
}
