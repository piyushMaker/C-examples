// Online C compiler to run C program online
#include <stdio.h>
#define maxq 10
char aq[maxq] = {0};
char s = 0, e =0;
typedef enum status {success = 0, fail = 1, error = -1} state;
typedef enum qstate {empty = 0, full = 1, notfull = -1} qstate;


void msgprt(char *ips)
{
    printf("%s\n", ips);
}

char popqueue()
{
    if (s == (maxq))
    {
        msgprt("Queue is done");
        return (char) error;
    }
    char temp = aq[s];
    s++;
    return temp;
}

state insert(char ins)
{
    if(e == maxq)
    {
        msgprt("Queue Full");
        return error;
    }
    aq[e] = ins;
    e++;
    return success;
}

void printqueue()
{
    for(int i = 0; i < maxq; i++)
    {
        printf("%c ", aq[i]);
    }
    printf("\n");
}

qstate qs()
{
    if(s == 0 && e == 0)
    {
       msgprt("queue is empty");
       return empty;
    }
    if(e < (maxq -1)  && e > 0)
    {
       msgprt("queue is not full");
       return notfull;
    }
    if(s == maxq && e == maxq)
    {
       msgprt("queue is full");
       return full;
    }
}

int main() {
    int state = 0;
    
    state = (int) qs();
    if (state == empty || state == notfull)
    {
        for(int i = 0; i <=maxq; i++)
        {
            int ret = (int)insert('a');
            if(ret == error)
            {break;}
        }
    }
    for(int i = 0; i <=maxq; i++)
    {
        char t = popqueue();
        if (t == error){break;}
        printf("%d -- %c", i,t);
    }
     //printqueue();
     printf("State of Q %d", (int)qs());
    

    return 0;
}
