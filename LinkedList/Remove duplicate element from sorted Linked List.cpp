//problem link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Node *removeDuplicates(Node *head)
{
    Node* prev = head, *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == prev->data) {
            curr = curr->next;
            prev->next = curr;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}