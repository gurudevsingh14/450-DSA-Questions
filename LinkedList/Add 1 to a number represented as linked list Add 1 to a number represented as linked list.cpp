//problem link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

Node* reverse(Node* head)
{
    Node *p = NULL, *q = NULL, *r = head;
    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    return q;
}
Node* addOne(Node *head)
{
    head = reverse(head);
    Node* temp = head, *prev = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        carry = temp->data / 10;
        temp->data %= 10;
        prev = temp;
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node* newnode = new Node(1);
        prev->next = newnode;
    }
    return reverse(head);
}