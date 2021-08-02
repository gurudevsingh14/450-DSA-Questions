//problem link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

int minSwaps(vector<int>&nums)
{
    int n = nums.size();
    vector<pair<int, int>>temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[i].first = nums[i];
        temp[i].second = i;
    }
    sort(temp.begin(), temp.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i].second != i)
        {
            swap(temp[temp[i].second], temp[i]);
            count++;
            i--;
        }
    }
    return count;
}