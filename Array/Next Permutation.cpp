//problem link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                int j;
                for (j = n - 1; j > i && nums[j] <= nums[i]; j--);//searching for number just greater than nums[i]

                swap(nums[i], nums[j]);

                reverse(nums.begin() + i + 1, nums.end());/*since the all the numbers after ith index will be in increasing order form left to right. 
                                                            so, instead of sorting we can just reverse them*/

                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};