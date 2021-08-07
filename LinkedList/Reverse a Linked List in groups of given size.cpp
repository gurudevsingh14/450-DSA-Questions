//problem link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

struct node *reverse (struct node *head, int k)
{
    struct node* newnode = new node(0);
    newnode->next = head;
    head = newnode;
    int count = 0;
    struct node *p = head, *q = head, *r = head->next, *tail = head;
    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
        count++;
        if (count == k)
        {
            node* temp = tail->next;
            tail->next->next = r;
            tail->next = q;
            tail = temp;
            q = tail;
            count = 0;
        }
    }
    if (count != 0)
    {
        node* temp = tail->next;
        tail->next->next = r;
        tail->next = q;
        tail = temp;
        q = tail;
    }
    return head->next;
}