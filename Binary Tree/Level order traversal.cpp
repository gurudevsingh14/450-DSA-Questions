//problem link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

vector<int> levelOrder(Node* node)
{
    queue<Node*>q;
    q.push(node);
    vector<int>ans;
    while (!q.empty())
    {
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);

        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}