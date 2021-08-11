#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int n) {
        val = n;
        left = NULL;
        right = NULL;
    }
};

void preorder(node* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void iterativePreorder(node* root)
{
    stack<node*>s;
    s.push(root);
    while (!s.empty())
    {
        cout << s.top()->val << " ";
        if (s.top()->left != NULL)
            s.push(s.top()->left);
        else
        {
            while (!s.empty() && s.top()->right == NULL)
            {
                s.pop();
            }
            if (!s.empty())
            {
                node* temp = s.top()->right;
                s.pop();
                s.push(temp);
            }
        }
    }
}
string print(int n)
{
    if (n == 1) return " st (root) ";
    else if (n == 2) return " nd ";
    else if (n == 3) return " rd ";
    else return " th ";
}
int main()
{
    int left, right, r;
    cout << "enter the value of root node : ";
    cin >> r;
    int count = 1;
    queue<node*>q;
    node* root = new node(r);
    node* temp = root, *p;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();

        //nodes are labeled level order wise and labeling is identical for each node :-
        cout << "enter value of left and right child of " << count << print(count) << "node : ";

        cin >> left;//enter -1 if their is no left child
        cin >> right;//enter -1 if their is no right child
        /*
        example input:
        5 3 6 2 4 -1 -1 -1 -1 -1 -1

        tree structure:

             5
            / \
           3   6
          / \
         2   4

        */
        if (left != -1) {
            p = new node(left);
            q.push(p);
            temp->left = p;
        }
        if (right != -1) {
            p = new node(right);
            q.push(p);
            temp->right = p;
        }
        q.pop();
        count++;
    }
    cout << endl;

    cout << "Preorder traversal :\n";
    preorder(root);
    cout << endl;

    cout << "Iterative Preorder traversal :\n";
    iterativePreorder(root);
    cout << endl;

    return 0;
}