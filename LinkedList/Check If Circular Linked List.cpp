//problem link: https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   Node *fast = head, *slow = head;
   while (fast != NULL && fast->next != NULL)
   {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
         return true;
   }
   return false;
}