//problem link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Node * removeDuplicates( Node *head)
{
    unordered_map<int, int> map;
    Node *prev = head, *curr = head->next;
    map[prev->data]++;
    while (curr != NULL)
    {
        if (map[curr->data] == 0)
        {
            map[curr->data]++;
            prev = prev->next;
            curr = curr->next;
        }
        else
        {
            curr = curr->next;
            prev->next = curr;
        }
    }
    return head;
}