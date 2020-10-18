/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> via(nums.size());
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(res, temp, via, nums, 0);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& via, const vector<int>& nums, int level){
        if(level == nums.size()) {
            res.push_back(temp);
            return;
        }
        for(int i =0; i < nums.size(); i++) {
            if(via[i] || (i > 0 && nums[i] == nums[i - 1] && !via[i - 1])) continue;
            temp.push_back(nums[i]);
            via[i] = 1;
            helper(res, temp, via, nums, level +1);
            temp.pop_back();
            via[i] =0;
        }
    }
};
// @lc code=end

