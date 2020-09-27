/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left =0, right = height.size() -1;
        int max_left = 0, max_right =0;
        int res =0;
        while (left < right) {
            if(height[left] < height[right]) {
                height[left] > max_left ? max_left = height[left] : res += max_left - height[left];
                left++; 
            } else {
                height[right] > max_right ? max_right = height[right] : res += max_right - height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

