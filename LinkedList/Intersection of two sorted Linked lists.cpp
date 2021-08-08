//problem link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

Node* findIntersection(Node* head1, Node* head2)
{
    Node *i = head1, *j = head2, *ans = new Node(0), *temp = ans;
    while (i != NULL && j != NULL)
    {
        if (i->data == j->data)
        {
            Node *newnode = new Node(i->data);
            temp->next = newnode;
            temp = temp->next;
            i = i->next;
            j = j->next;
        }
        else if (i->data < j->data)
        {
            i = i->next;
        }
        else
        {
            j = j->next;
        }
    }
    return ans->next;
}