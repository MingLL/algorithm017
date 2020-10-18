/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(res, 1, n, k);
        return res;
    }
    void helper(vector<vector<int>>& res,int level, int n, int k) {
        // 当获取的数据个数，加上剩下所罕有的数据个数小于要包含的数据个数则证明该解无效，直接返回
        if (nums.size() + (n - level + 1) < k) {
            return;
        }
        // 找到可行解
        if(nums.size() == k) {
            res.push_back(nums);
            return;
        }
        //选择当前层的数据
        nums.push_back(level);
        helper(res, level +1, n, k);
        nums.pop_back();
        // 不选当前层的数据
        helper(res, level +1, n, k);
    }
};
// @lc code=end

