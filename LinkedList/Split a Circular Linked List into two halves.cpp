//problem link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head, *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    Node* curr = slow->next;
    while (curr->next != head)
        curr = curr->next;
    curr->next = *head2_ref;
    slow->next = head;
}