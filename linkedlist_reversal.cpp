/**
 * @file bst_transversal.cpp
 * @author Piyush Supe (https://github.com/piyushMaker)
 * @brief : Demostrate Recursive creation of linked list, and Reversing linked list iterative as well as Recursive way.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

#define LLLEN 3 //Number of Nodes to be created
#define NODEVALUE 0 //headnodes data value

typedef struct ll{
    int a;
    struct ll *next;
}lln;

lln * allocate(lln* node, int key)
{
    node = (lln*) malloc(1*sizeof(lln));
    node->a = key;
    node->next = NULL;
    return node;
}

lln* attachnode(lln * node, int key)
{
    lln * temp = NULL;
    if (key > LLLEN)
    {
        return 0;
    }
    if (node == NULL)
    {
        temp = allocate(node , key);
    }
    //key = key + 1;
    temp->next = attachnode(temp->next, ++key);
    return temp;
}

void transverse(lln *node)
{
    cout << "Transvesing " << endl;
    while(node != NULL)
    {
        cout << "Node " << node->a << endl;
        node = node->next;
    }
}

//Iterative way Preferred one
lln* reverse_ll(lln* node)
{
    lln * prev = NULL;
    lln * curr = NULL;
    lln * next = NULL;

    curr = node;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

/*Recurrsive way, Still wondering why one would use this considering the space complexity, 
think of stacking function on function and so on.. think of a 100,000 linkedlist nodes eww!*/
/* But tests you understanding about recurssion in complex way */

lln* rever_rec(lln* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }    

    lln* newhead = rever_rec(head->next); //newhead = node3  // Just finds the Reverse head.
    //cout << "Returned to head: " << head->a << endl; 
    //cout << "Returned head value: " << newhead->a << endl;
    lln* headnext = head->next; //headnext = node3 //headnext = node2   //headnext = node1
    headnext->next = head;  //node3.next = node2   //node2.next = node1 //node1.next = node0
    head->next = NULL;  //node2.next = Null        //node1.next = NUll  //node0.next = NULL

    return newhead; //node 3
}


int main()
{
    lln *revNode = NULL, *headnode = NULL;
    headnode = attachnode(headnode, NODEVALUE);
    transverse(headnode);
    headnode = reverse_ll(headnode); //Iterative
    transverse(headnode);
    headnode = rever_rec(headnode); //Recursive
    transverse(headnode);
    return 0;
}
