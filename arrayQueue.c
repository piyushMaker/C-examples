#include <stdio.h>
#define MAX 10
int queue[MAX];
int push = 0;
int pop = -1;

int isfull()
{
	if(push == MAX)
		return 1;
	else
		return -1;
}

int isempty()
{
	if(push == 0 && pop == -1)
		return 1;
	else
		return -1;
}

int insert(int elm)
{
	if(isfull() < 0)
	{
		queue[push] = elm;
		push += 1;
		pop = push - 1;
		return 1;
	}
	return -1;
}

int rem()
{
	int ret = 0;
	if (pop < 0)
	{
		return -1;
	}
	ret = queue[pop];
	pop -= 1;
	push = pop + 1;
	return ret;
}

int main(void)
{
	int ret;
	for(int a = 0; a < MAX; a++)
	{
		if(insert(a) < 0)
			printf("%s\n","Failed to insert");
	}
	for(int a = 0; a < MAX; a++)
	{
		ret = rem();
		if (ret < 0)
			printf("%s\n", "Nothing to Pop");
		else
			printf("Popped %d\n", ret);
	}

	return 0;
}