/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ring_substitution(nums, k);
    }
/**
 * 暴力破解法。
 * 时间复杂度为O(n*k)
 * 空间复杂度为O(1)
 * 超时解法
 */ 
    void violent_solution(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i = 0; i < k; i++) {
            int num = nums[size -1];
            for(int j = size -1; j >0; j--) {
                nums[j] = nums[j -1];
            }
            nums[0] = num;
        }
    }

/**
 * 反转解法
 * 时间复杂度为O(n)
 * 空间复杂度为O(1)
 */
    void reverse(vector<int>& nums, int k) {
        int num = k % nums.size();
        reverse_t(nums, 0, nums.size() -1);
        reverse_t(nums, 0, num -1);
        reverse_t(nums, num, nums.size() -1);

    }
    void reverse_t(vector<int>& nums, int start, int end) {
        while(start > end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

/**
 * 环形移动
 * 时间复杂度为O(n)
 * 空间复杂度为O(1)
*/
    void ring_substitution(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        //数组中已经遍历过的数字个数
        int count =0;
        for(int start = 0; count < size; start++) {
            int current =  start;
            //往前移动的数字
            int prev = nums[start];
            do{
                int next = (current + k) % size;
                // 保存被替换的数字
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(start != current);
        }
    }
};
// @lc code=end

