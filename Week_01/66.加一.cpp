/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size() -1;
        for(int i =size ;i >= 0; i--) {
            digits[i]++;
            digits[i] %=10;
            if(digits[i] != 0) {
                return digits;
            }
        }
        vector<int> res(digits.size() +1, 0);
        res[0] = 1;
        return res;
    }
};
// @lc code=end

