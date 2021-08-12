//problem link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

vector<int> topView(Node *root)
    {   
        vector<int>ans;
        if(!root)
        return ans;
        map<int,int>map;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {   
            Node* first=q.front().first;
            int second=q.front().second;
            q.pop();
            if(map[second]==0)
            map[second]=first->data;
            if(first->left)
                q.push({first->left,second-1});
            if(first->right)
                q.push({first->right,second+1});
        }
        for(auto x:map)
        {
            ans.push_back(x.second);
        }
        return ans;
    }