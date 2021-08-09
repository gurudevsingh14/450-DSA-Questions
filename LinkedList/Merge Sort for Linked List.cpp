//problem link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

Node* merge(Node* head, Node* mid)
{
    Node* ans = new Node(0);
    Node *temp = ans;
    while (head != NULL && mid != NULL)
    {
        if (head->data <= mid->data) {
            temp->next = head;
            head = head->next;
        }
        else
        {
            temp->next = mid;
            mid = mid->next;
        }
        temp = temp->next;
    }
    while (head != NULL)
    {
        temp->next = head;
        head = head->next;
        temp = temp->next;
    }
    while (mid != NULL)
    {
        temp->next = mid;
        mid = mid->next;
        temp = temp->next;
    }
    return ans->next;
}
Node* mergeSort(Node* head) {
    if (head->next == NULL)
        return head;
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    slow->next = NULL;
    Node *head1 = mergeSort(head);
    Node *head2 = mergeSort(mid);
    Node *ans = merge(head1, head2);
    return ans;
}