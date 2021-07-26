//problem link: https://leetcode.com/problems/rotate-image/

void rotate(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n; j++)
            swap(m[i][j], m[n - i - 1][j]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(m[i][j], m[j][i]);
}