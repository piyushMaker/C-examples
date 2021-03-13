#include <stdio.h>

void multiptr(int *arg)
{
        printf("%c\n",arg[2][0]);
}
 char str1[] = "Piyush";
 char str2[] = "Shourya";
 char str3[] = "Bhavana";
char* array[3]; // = {1,2,3,4,5,6};
int main()
{

    array[0] = str1;
    array[1] = str2;
    array[2] = str3;
    multiptr(array);
    //printf("Hello World");

    return 0;
}
