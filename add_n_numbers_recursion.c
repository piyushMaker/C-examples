// Powered by iNeuron
#include <stdio.h>

#define FIRSTNNUMBERS 5
#define ARRYSIZE FIRSTNNUMBERS //

int arrInt[ARRYSIZE] = {0};
int raddn = 0;

int printfun(int i)
{
    int addn = 0;
    if(i > ARRYSIZE)
    {
        return 0;
    }
    arrInt[i-1] = i;
    addn += i;
    addn += printfun(i + 1);
    return addn;
}

int main(void) {
    raddn = printfun(1);
    for(int n = 0; n <ARRYSIZE; n++)
    {
        printf("%d ", arrInt[n]);
    }
    printf("\n%d", raddn);
    return 0;
}
