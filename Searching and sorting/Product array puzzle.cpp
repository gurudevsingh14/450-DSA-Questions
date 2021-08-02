//problem link: https://practice.geeksforgeeks.org/problems/product-array-puzzle/0

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    long long int prod = 1;
    vector<long long int>ans(n, 1);
    long long int temp = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = ans[i] * temp;
        temp *= nums[i];
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * temp;
        temp *= nums[i];
    }
    return ans;
}