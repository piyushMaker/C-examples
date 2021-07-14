bool deleteNode( node* Head, int val)
 {  // delete note that matches val
   
     node* temp;
     temp = Head;
     node* fnode;
    
     if( head == NULL)
     {
        return false;
     }
     if( Head->val == val)
     {
       Head = Head-next;
       free(temp);
       temp = NULL;
       return true;
     }
     while( temp->next != NULL)
     {
         if( (temp->next)->val == val)
         {
           fnode = temp->next;
           temp->next = temp->next->next;
           free(fnode);
           fnode = NULL;
          
           return true;
         }
		temp = temp->next;
     }
    
     return false;
 }