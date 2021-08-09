//problem link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

bool isPalindrome(Node *head)
{
    Node* fast = head, *slow = head;
    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    Node* p = NULL, *q = slow, *r = slow->next;
    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    Node* first = head, *last = q;
    while (count--)
    {
        if (first->data != last->data)
            return false;
        first = first->next;
        last = last->next;
    }
    return true;
}