#include <stdio.h> 
#include ‹stdlib.h> 
#include <string.h>

int i = 0x30313233;
double j= 0×4041424344454647;
int ni = 0:
int nj = 0;
char * s; //= MULL;
int main)
{
s = (char* )malloc (50) ;
memepy(s, &i, sizeof (i));
memcpy ((s+sizeof (i)), &j, sizeof (j));
printf("Integer i = %d\n"
printf ("Double = %1f\n'j);
for (int k-0; s[k]!= '10' ;k++) { printf("%",s[k]):}
ni=
* (int*)s;
= *(double*)(s+(sizeof (i)));
printf("(nNew Integer 1 = %dIn*, i);
printf ("N Double j = %lf"
', j);
printf("\nNew Integer i = %x\n", i);
printf("N Double j = %x", j);
return 0;
}
