//problem link: https://practice.geeksforgeeks.org/problems/max-rectangle/1
//suggestion: first solve Largest Rectangle in Histogram before moving to this problem (problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/)

class Solution {
public:
    int largestRectangleArea(int heights[], int n) {
        stack<int>stack;
        vector<int>right(n, 0);
        vector<int>left(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && heights[stack.top()] > heights[i])
            {
                right[stack.top()] = (i - 1);
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty())
        {
            right[stack.top()] = (n - 1);
            stack.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack.empty() && heights[stack.top()] > heights[i])
            {
                left[stack.top()] = (i + 1);
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty())
        {
            left[stack.top()] = 0;
            stack.pop();
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * ((right[i] - left[i]) + 1);
            ans = max(ans, area);
        }
        return ans;
    }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        int ans = largestRectangleArea(matrix[0], m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
            }
            ans = max(ans, largestRectangleArea(matrix[i], m));
        }
        return ans;
    }
};