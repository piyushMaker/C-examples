#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * a;
char str[] = "Heron Formula.";
int main()
{
 a = str;
 printf("%s\n", a);
 printf("%ld %ld\n",sizeof(str), strlen(a));
 for(int i = 0; i<sizeof(str); i++ )
 {
     printf(" %c0x%x", a[i], a[i]); 
 }
 
    
    return 0;
}