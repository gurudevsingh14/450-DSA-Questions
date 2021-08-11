/*
Input:
        5
       / \
      3   6
     / \
    2   4
Output:

Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2

Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

*/
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

void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

string print(int n)
{
    if (n == 1) return " st (root) ";
    else if (n == 2) return " nd ";
    else if (n == 3) return " rd ";
    else return " th ";
}
void mirrorimage(node* root, node** mirror)
{
    if (root == NULL)
        return;
    (*mirror) = new node(root->val);
    mirrorimage(root->left, &(*mirror)->right);
    //(*mirror) = new node(root->val);
    mirrorimage(root->right, &(*mirror)->left);
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

    node* mirror;

    mirrorimage(root, &mirror);

    cout << "Level order traversal of original binary tree:\n";
    inorder(root);
    cout << endl;

    cout << "Level order traversal of mirror image:\n";
    inorder(mirror);

    return 0;
}