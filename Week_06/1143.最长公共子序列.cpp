/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if(m < 1 || n < 1) return 0;
        int dp[m +1][n +1];
        memset(dp, 0, sizeof(dp));
        for(int i =1; i <= m; i++) {
            for(int j =1; j <= n; j++) {
                if(text1[i -1] == text2[j -1]) {
                    dp[i][j] = dp[i -1][j -1] +1;
                } else {
                    dp[i][j] = max(dp[i][j -1], dp[i -1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

