//problem link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        vector<int>temp = intervals[0];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= temp[1]) {
                temp = {min(temp[0], intervals[i][0]), max(temp[1], intervals[i][1])};
            }
            else {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        if (temp.size() > 0)
            ans.push_back(temp);
        return ans;
    }
};