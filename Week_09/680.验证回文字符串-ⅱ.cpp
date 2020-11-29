/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int begin =0, end = s.size() -1;
        while(begin < end) {
            if(s[begin] == s[end]) {
                begin++;
                end--;
            } else {
                return checkPalindrome(s, begin, end -1) || checkPalindrome(s, begin +1, end);
            }
        }
        return true;
    }

    bool checkPalindrome(const string& str, int begin, int end) {
        while(begin < end) {
            if(str[begin++] != str[end--])
                return false;
        }
        return true;
    }
};
// @lc code=end

