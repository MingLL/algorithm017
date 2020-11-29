/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int map[128] = { 0 };
        int left =0, right =0, need =0;
        for(int i =0; i< p.size(); i++) {
            map[p[i]]++;
        }
        while(right < s.size()) {
            if(map[s[right]] > 0) need++;
            map[s[right]]--;
            right++;
            while(need == p.size()) {
                if(right -left == p.size()) res.push_back(left);
                if(map[s[left]] == 0) need--;
                map[s[left]]++;
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

