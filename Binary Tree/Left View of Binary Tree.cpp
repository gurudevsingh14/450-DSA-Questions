//problem link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

vector<int> leftView(Node *root)
{
    queue<Node*>q;
    vector<int>ans;
    if (!root)return ans;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        while (n--)
        {
            Node* temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}