//problem link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

vector<int> rightView(Node *root)
{
    vector<int>ans;
    if (!root) return ans;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.back()->data);
        while (n--)
        {
            Node* temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}