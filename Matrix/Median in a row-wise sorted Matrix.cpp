//problem link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
public:
    int countele(vector<int>arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c) {
        int low = 1;
        int high = 2000;
        int mid;
        int target = (r * c) / 2 + 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            int count = 0;// total count of elements <= mid in matrix
            for (int i = 0; i < r; i++)
            {
                count += countele(matrix[i], mid);// function that returns count of elements <= mid in i th row
            }
            if (count >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};