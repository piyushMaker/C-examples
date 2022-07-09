// Powered by iNeuron
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char stg[] = "malayalam";
char *str1, *str2;

int main(void) {
    int halflen;
    int len = strlen(stg);
    halflen = floor(len/2);
    str1 = (char*) malloc(halflen*sizeof(char));
    str2 = (char*) malloc(halflen*sizeof(char));
    strncpy(str1,stg, halflen);
    //printf("%s", str1);
    for(int n = 0 ; n < halflen; n++)
    {
        str2[halflen - 1 - n] = str1[n];
    }
    printf("\n%s\n", str2);
    printf("%s\n",(stg + (len - halflen)));
    if(strcmp(str2, (stg + (len - halflen)))  == 0)
        printf("palindrom");
    else
        printf("not a palindrome");
    return 0;
}
