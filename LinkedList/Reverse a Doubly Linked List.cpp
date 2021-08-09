//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#

Node* reverseDLL(Node * head)
{   
    Node* temp=head,*prev=NULL;
    while(temp!=NULL)
    {   
        swap(temp->next,temp->prev);
        prev=temp;
        temp=temp->prev;
    }
    return prev;
}