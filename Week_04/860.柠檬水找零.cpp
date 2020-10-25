/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBills =0, tenBills =0;
        for(int bill : bills) {
            if(bill == 5) {
                fiveBills++;
            } else if (bill == 10) {
                if(fiveBills < 1) {
                    return false;
                }
                fiveBills--;
                tenBills++;
            } else {
                if(tenBills > 0 && fiveBills > 0) {
                    tenBills--;
                    fiveBills--;
                } else if(fiveBills > 3) {
                    fiveBills -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

