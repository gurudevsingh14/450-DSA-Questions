//problem link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    stack<Node*>a;
    stack<Node*>b;
    Node* temp = first;
    while (temp != NULL)
    {
        a.push(temp);
        temp = temp->next;
    }
    temp = second;
    while (temp != NULL)
    {
        b.push(temp);
        temp = temp->next;
    }
    int carry = 0;
    int sum = 0;
    while (!a.empty() && !b.empty())
    {
        Node* num1 = a.top();
        Node* num2 = b.top();
        sum = num1->data + num2->data + carry;
        num1->data = sum % 10;
        carry = sum / 10;
        a.pop();
        b.pop();
    }
    while (!a.empty())
    {
        sum = a.top()->data + carry;
        a.top()->data = sum % 10;
        carry = sum / 10;
        a.pop();
    }
    while (!b.empty())
    {
        sum = b.top()->data + carry;
        Node *newnode = new Node(sum % 10);
        carry = sum / 10;
        newnode->next = first;
        first = newnode;
        b.pop();
    }
    while (carry > 0)
    {
        Node* newnode = new Node(carry % 10);
        carry /= 10;
        newnode->next = first;
        first = newnode;
    }
    return first;
}