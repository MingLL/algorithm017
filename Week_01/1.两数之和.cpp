/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        vector<int> res(2);
        for(int i =0; i < nums.size(); i++) {
            if(map.count(target - nums[i]) >0) {
                res[1] = i;
                res[0] = map[target -nums[i]];
                break;
            }
            map[nums[i]] = i;
        } 
        return res;
    }
};
// @lc code=end

