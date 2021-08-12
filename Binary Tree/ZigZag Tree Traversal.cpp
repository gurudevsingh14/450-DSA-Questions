//problem link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

vector <int> zigZagTraversal(Node* root)
{
    vector<int>ans;
    if (!root)
        return ans;
    queue<Node*>q;
    q.push(root);
    int toggle = 0;
    while (!q.empty())
    {
        int s = q.size();
        vector<int>temp;
        while (s--)
        {
            if (q.front()->left)
                q.push(q.front()->left);

            if (q.front()->right)
                q.push(q.front()->right);

            temp.push_back(q.front()->data);
            q.pop();
        }
        if (toggle % 2 != 0)
            reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);

        toggle++;
    }
    return ans;
}