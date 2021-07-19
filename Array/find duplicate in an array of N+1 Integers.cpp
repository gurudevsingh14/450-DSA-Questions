//problem link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])]>=0)
                nums[abs(nums[i])]=-nums[abs(nums[i])];
            else
                return abs(nums[i]);
        }
        return -1;
    }
};