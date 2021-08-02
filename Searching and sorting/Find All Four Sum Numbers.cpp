//problem link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

vector<vector<int> > fourSum(vector<int> &a, int target) {
    vector<vector<int>>ans;
    int n = a.size();
    sort(a.begin(), a.end());
    int w, x, y, z;
    for (int w = 0; w < n - 3; w++)
    {
        if (w > 0 && a[w] == a[w - 1])continue;
        for (int x = w + 1; x < n - 2; x++)
        {
            if (x > w + 1 && a[x] == a[x - 1])continue;
            y = x + 1;
            z = n - 1;
            while (y < z)
            {
                int sum = a[w] + a[x] + a[y] + a[z];
                if (sum == target) {
                    ans.push_back(vector<int> {a[w], a[x], a[y], a[z]});
                    while (y < z && a[y] == a[y + 1]) {
                        y++;
                    }
                    while (y < z && a[z] == a[z - 1]) {
                        z--;
                    }
                }
                if (sum < target)
                    y++;
                else
                    z--;
            }
        }
    }
    return ans;
}