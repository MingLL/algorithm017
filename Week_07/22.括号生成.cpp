/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, 0,0,n,"");
        return res;
    }

    void helper(vector<string>& res, int left, int right, int n, string s) {
        if(left == n && right ==n) {
            res.push_back(s);
            return;
        }
        if(left < n) {
            helper(res, left +1, right, n, s+'(');
        }
        if(right < left) {
            helper(res, left, right +1, n, s+')');
        }
    }
};
// @lc code=end

