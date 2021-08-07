#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    node(int n)
    {
        data = n;
        next = NULL;
    }
};
void create(int a[], int n, struct node **head)
{
    if (n == 0) {
        *head = NULL;
        return;
    }
    int i;
    struct node *first = new node(a[0]);
    *head = first;
    for (int i = 1; i < n; i++)
    {
        struct node *p = new node(a[i]);
        first->next = p;
        first = p;
    }
}
void display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << "\n";
}
void MoveLastElementToFront(struct node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next->next = *head;
    *head = temp->next;
    temp->next = NULL;
}
int main()
{
    struct node *head = NULL;
    int a[] = {1, 2, 3, 4, 5};

    create(a, 5, &head);
    display(head);
    MoveLastElementToFront(&head);
    display(head);
}
