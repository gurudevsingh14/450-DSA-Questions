//problem link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

void removeLoop(Node* head)
{
    Node* slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}