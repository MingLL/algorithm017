/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0, right = nums.size() -1;
        while(left < right) {
            int mid = left + (right -left) /2;
            if(nums[mid] == target) return mid;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                left = mid + 1;
            else
                right = mid;
        }
        if(nums[left] == target) return left; 
        return -1;
    }
};
// @lc code=end

