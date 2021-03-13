/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 typedef struct linkedlist{
    int data;
    struct linkedlist *pointer;
}createnode;

createnode node1, node2, node3, *tempHead;

void trans(createnode *head)
{
    int nodenum = 1;
    tempHead = head;
    
    while(1){
        printf("nodenum %d, data %d\n", nodenum, tempHead->data);
       printf("Never change data node1 %d\n", head->data);
        if(tempHead->pointer == NULL)
            break;
        tempHead = tempHead->pointer;
        
        nodenum ++;
        if (nodenum > 5)
        {break;}
    }
    
}


int main()
{
    node1.data = 10;
    node1.pointer = &node2;
    
    node2.data = 20;
    node2.pointer = &node3;
    
    node3.data = 30;
    //node3.pointer = NULL;
    node3.pointer = &node1;
     //transverseing
    trans(&node1);

    return 0;
}
