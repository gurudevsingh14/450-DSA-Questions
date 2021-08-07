//problem link: https://leetcode.com/problems/linked-list-cycle-ii/

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            if (slow == head)
                return head;
            else
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }
    return NULL;
}