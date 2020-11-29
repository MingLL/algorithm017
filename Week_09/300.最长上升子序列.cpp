/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dp[nums.size()];
        dp[0] = 1;
        int maxLength = 1;
        for(int i = 1; i < nums.size(); i++) {
            int maxval = 0;
            for(int j =0; j < i; j++) {
                if(nums[i] > nums[j]){
                    maxval = max(maxval, dp[j]);
                }                
            }
            dp[i] = maxval +1;
            maxLength = max(maxLength,dp[i]);
        }
        return maxLength;
    }
};
// @lc code=end

