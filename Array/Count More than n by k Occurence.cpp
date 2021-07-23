//problem link: https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

class Solution
{
public:
    int countOccurence(int arr[], int n, int k) {
        map<int, int>m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        int t = n / k;
        int count = 0;
        for (auto x : m)
        {
            if (x.second > t)
                count++;
        }
        return count;
    }
};