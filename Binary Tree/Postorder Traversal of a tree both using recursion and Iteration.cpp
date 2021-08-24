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

void postorder(node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void iterativePostorder(node* root)
{
    stack<node*>s;
    s.push(root);
    stack<node*>ans;
    node* temp = root;
    while (!s.empty())
    {
        temp = s.top();
        ans.push(temp);
        s.pop();
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    while (!ans.empty()) {
        cout << ans.top()->val << " ";
        ans.pop();
    }
    cout << endl;
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

    cout << "Postorder traversal :\n";
    postorder(root);
    cout << endl;

    cout << "Iterative Postorder traversal :\n";
    iterativePostorder(root);
    cout << endl;

    return 0;
}