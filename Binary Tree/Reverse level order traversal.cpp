//problem link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*>q;
    q.push(root);
    vector<int>ans;
    while (!q.empty())
    {
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        if (q.front()->left != NULL)
            q.push(q.front()->left);

        ans.push_back(q.front()->data);
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}