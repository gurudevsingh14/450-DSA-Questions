//problem link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

int length(Node* head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
int intersectPoint(Node* head1, Node* head2)
{
    int n1 = length(head1);
    int n2 = length(head2);

    if (n1 >= n2)
    {
        int diff = n1 - n2;
        while (diff--)
            head1 = head1->next;
    }
    else
    {
        int diff = n2 - n1;
        while (diff--)
            head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}