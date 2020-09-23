/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        solution2(nums);
    }

    void solution1(vector<int>& nums) {
        int j =0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                if(j != i) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }

    void solution2(vector<int>& nums) {
        int size = nums.size();
        for(int i =0, j =0; i < size; i++) {
            if (nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }

};
// @lc code=end

