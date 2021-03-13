/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *pointer;
}createnode;
 int totalNodes = 0;
createnode *headnode, *lastnode;

void trans(createnode *head)
{
    int nodenum = 1;
    createnode *tempHead = head;
    
    while(1){
        printf("nodenum %d, data %d\n", nodenum, tempHead->data);
       printf("Never change data node1 %d\n", headnode->data);
        if(tempHead->pointer == NULL)
            break;
        tempHead = tempHead->pointer;
        
        nodenum ++;
        //if (nodenum > 5)
        //{break;}
        totalNodes ++;
    }
    
}

void addNodes(int rxd)
{   
    createnode *temp; 
    //As we call this function every time we create node
    //we should allocate new space new node
    temp = (createnode *)malloc(sizeof(createnode) *1);
    temp->data = rxd;
    temp->pointer = NULL; //For Circular replace NULL with &headnode
    //update lastnode ptr new node address
    lastnode->pointer = temp;
    //make new node as last node
    lastnode = temp;
    totalNodes ++;
}

void addHeadNode(int rxd)
{
    headnode = (createnode *)malloc(sizeof(createnode) *1); 
    headnode->data = rxd;
    headnode->pointer = NULL;
    lastnode = headnode;
    totalNodes ++;
}

void replaceHead(int rxd)
{
    createnode *temp;
    temp = (createnode *)malloc(sizeof(createnode) *1);
    temp->data = rxd;
    //add headnode address to temp->pointer
    temp->pointer = headnode;
    //temp as Headnode
    headnode = temp;
    totalNodes ++;
}

void insertNode(createnode *head, int rxd, int posN)
{   
    if(posN < totalNodes)
    {
        createnode *tempNode, *scroll;
        tempNode = (createnode *)malloc(sizeof(createnode)*1);
        //tempNode = head;
        scroll = head;
        for(int loop = 1; loop < posN; loop++)
        {
            scroll = scroll->pointer; //PREV LOCn
        }
        //tempNode will have pos -1 ptr
        tempNode->pointer = scroll->pointer;
        scroll->pointer = tempNode;
        tempNode->data = rxd;
    }
}

int main()
{
    addHeadNode(0);
    //addNodes
    addNodes(1);
    addNodes(2);
    addNodes(3);
    addNodes(4);
    addNodes(5);
    addNodes(10);
    replaceHead(99);
    insertNode(headnode, 77, 5);
    insertNode(headnode, 88, 4);
    insertNode(headnode, 54, 3);
    //transverseing
    trans(headnode);
    //printf("No of Nodes %d\n", totalNodes);
    

    return 0;
}
