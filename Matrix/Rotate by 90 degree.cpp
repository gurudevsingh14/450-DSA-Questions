//problem link: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

void rotate(vector<vector<int> >& m)
{
    int n = m.size();
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n; j++)
            swap(m[j][i], m[j][n - i - 1]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(m[j][i], m[i][j]);
}