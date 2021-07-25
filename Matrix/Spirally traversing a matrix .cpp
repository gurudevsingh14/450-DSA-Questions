//problem link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
    vector<int>ans;
    int i = 0, j = 0;
    while (i < r && j < c)
    {   
        //traversing first row  
        for (int k = j; k < c; k++)
        {
            ans.push_back(matrix[i][k]);
        }
        i++;
        //traversing last column
        for (int k = i; k < r; k++)
        {
            ans.push_back(matrix[k][c - 1]);
        }
        c--;
        //traversing last row
        if (i < r) {
            for (int k = c - 1; k >= j; k--)
            {
                ans.push_back(matrix[r - 1][k]);
            }
            r--;
        }
        //traversing first column
        if (j < c) {
            for (int k = r - 1; k >= i; k--)
            {
                ans.push_back(matrix[k][j]);
            }
            j++;
        }
    }
    return ans;
}