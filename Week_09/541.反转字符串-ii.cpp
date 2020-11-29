/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i < s.length(); i += (2*k)) {
            if(i +k <= s.length()) {
                reverse(s.begin() +i, s.begin() +i +k);
                continue;
            }
            reverse(s.begin() +i, s.end());
        }
        return s;
    }
};
// @lc code=end

