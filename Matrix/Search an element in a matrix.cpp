//problem link: https://leetcode.com/problems/search-a-2d-matrix/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m - 1;
    int mid;
    int r = 0;
    //searching for row where target may exist
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] > target)
            high = mid - 1;
        else {
            low = mid + 1;
            r = max(r, mid);
        }
    }
    low = 0;
    high = n - 1;
    //searching for target in row
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (matrix[r][mid] == target)
            return true;
        else if (matrix[r][mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}