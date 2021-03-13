/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct abc{
    int a;
    int b; 
    char c;
    char *buff;
};
int main()
{
    char str[] = "Piyush";
    struct abc v = {
        .a= 90,
        .b = 80,
        .c= 'A',
        .buff = "HelloWorld"
     };
    printf("%d %d %c %s", v.a, v.b, v.c, v.buff);

    return 0;
}
