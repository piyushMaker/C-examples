/**
 * @file bst_transversal.cpp
 * @author Piyush Supe (https://github.com/piyushMaker)
 * @brief : Demostrate Creation of BST and In, Pre and Post order transversal
            Demonstrate Node deletion ising Inorder Successor and verifing with inorder print.
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#define DELETE 1

using namespace std;


typedef enum status{fail = 1, success = 0}status;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

#if DELETE
    int global_is_key;
    struct node *global_del_found_node, *global_successor_parent_node;
#endif

struct node * createnode(struct node * newnode, int data)
{
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node * insert(struct node * insnode, int value)
{
    /*For the first time creates and return the root Node with valuse 20 as insnode is NULL at t=0
     Second time, insnode is not null, but insnode left and right are null so code goes into recursion
     create the new node and back trace happens*/

    if (insnode == NULL) //Check for root node
        {
            struct node * tempStore = createnode(insnode, value);
            return tempStore;
        }

    if (value < insnode->data) //Insert data to left
    {
        insnode->left = insert(insnode->left, value);
        //cout <<"Inserted to Left: " << value << endl;
    }
    if (value > insnode->data) //Insert data to right
    {
        insnode->right = insert(insnode->right, value);
        //cout <<"Inserted to Right: " << value << endl;
    }
    
    return insnode;
}

int inorder(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);

    return 0;
}

int preorder(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    cout << root->data << endl;
    inorder(root->left);
    inorder(root->right);

    return 0;
}

int postorder(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << endl;
    return 0;
}

//Deleting Node.
#if DELETE

int successorParent(struct node * root, int key)
{
    if(root == NULL)
    {
        return 1;
    }
    if (root->data == key)
    {
        return 5;
    }
    if(key < root->data)
        if (successorParent(root->left, key) == 5)
        {
            global_successor_parent_node = root;
            return 0;
         }

    if(key > root->data)
        if(successorParent(root->right, key) == 5)
        {
            global_successor_parent_node = root;
            return 0;
        }
    return 0;
}


int inordfind(struct node * root, int key)
{
    if(root == NULL)
    {
        return 1;
    }
    if (root->data == key)
    {
        global_del_found_node = root;
        return 0;
    }
    if(key < root->data)
        inordfind(root->left, key);
    if(key > root->data)
        inordfind(root->right, key);

    return 0;
}

int in_successor(struct node * root) //root is To be deleted Node's right Node address.
{
    static int i = 0;
    if(root == NULL)
    {
        return 1;
    }
    if(root->data < global_is_key)
    {
        global_is_key = root->data;
    }
    //cout << "succerr val " << global_is_key << endl;
    in_successor(root->left);
    in_successor(root->right);
    
    return 0;
}

int deleteNode(struct node * root, int key)
{
    if(inordfind(root, key) == 0)  //Find node to be deleted address
    {
        struct node * temp; 

        //Handling Leaf Node.
        if(global_del_found_node->left == NULL && global_del_found_node->right == NULL)
        {
            if (successorParent(root, global_del_found_node->data) == 0) //successor parent node
            {
                if (global_successor_parent_node->data > global_del_found_node->data)
                    global_successor_parent_node->left = NULL;
                if (global_successor_parent_node->data < global_del_found_node->data)
                    global_successor_parent_node->right = NULL;
            }
            free(global_del_found_node);
            return 0;
        }

        //cout << "Address of the Node" << global_del_found_node->data << endl;
        global_is_key = global_del_found_node->right->data;
        in_successor(global_del_found_node->right); //global_is_key updated find the successor
        temp = global_del_found_node;  //Temp store to be deleted node
        //global_is_key is updated in in_succcessor function.
        inordfind(root, global_is_key);// updates globla_del_found_node with successor node
        //global_del_found_node
        if (successorParent(root, global_is_key) == 0) //successor parent node
        {
            if (global_successor_parent_node->data > global_is_key)
                global_successor_parent_node->left = NULL;
            if (global_successor_parent_node->data < global_is_key)
                global_successor_parent_node->right = NULL;
        }
        free(global_del_found_node); //Delete Successor Node 181 Line
        temp->data = global_is_key; //copy successor value in Node to be deleted value

    }     // Get node with key 
    else{
        //cout << "Node With key not found" << endl;
        return 1;
    }
    return 0 ;
}
#endif

/*      20
    10      30
   5 14    25 33 */
int main()
{

    struct node * root = NULL;  
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 14);
    insert(root, 30);
    insert(root, 25);
    insert(root, 33);
    
    cout << "Tree formation done" << endl;

    cout << "Inorder Print" << endl;
    inorder(root);

    cout << "Preorder Print" << endl;
     preorder(root); 

    cout << "Postorder Print" << endl;
    postorder(root);   

#if DELETE  
    cout << "deleting node" << endl;
    if (deleteNode(root, 25) == 0)
    {
        cout << "successor: " << global_is_key << endl;
    }
    else{
        cout << "no node with that key" << endl;
    }

    cout << "INorder Print" << endl;
    inorder(root); 
#endif
    return 0;
}
