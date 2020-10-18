/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0, nums.size());
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> &nums, int level, int len) {
        if(level == len) {
            res.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]);
            helper(res, nums, level +1, len);
            swap(nums[i], nums[level]);
        }
    }
};
// @lc code=end

