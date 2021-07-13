#include<stdio.h>

void intdouble(int a)
{
	printf("%d\n", (a*2));
}
void callback(void (*funx)(int), int i)
{
	funx(i);
}

int main(void)
{
	void (*funcptr)(int);
	funcptr = intdouble;
	callback(funcptr, 5);
	return 0;
}