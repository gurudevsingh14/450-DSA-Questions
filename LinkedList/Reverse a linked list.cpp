//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#

struct Node* reverseList(struct Node *head)
    {
        struct Node* p=NULL,*q=NULL,*r=head;
        while(r!=NULL)
        {   
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        return q;
    }