//problem link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution {
public:
    int new_index(vector<int>arr, int index)
    {
        int i;
        for (i = index - 1; i >= 0; i--)
        {
            if (arr[i] == 0) {
                break;
            }
            else
                index--;
        }
        return index;
    }
    int rowWithMax1s(vector<vector<int> > matrix, int n, int m) {
        int ans = -1;
        int index = m;
        for (int i = 0; i < n; i++)
        {
            int curr = new_index(matrix[i], index);
            if (curr < index) {
                ans = i;
                index = curr;
            }
        }
        return ans;
    }

};