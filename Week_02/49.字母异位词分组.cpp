/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(string s :strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for(auto& a: map) {
            res.push_back(a.second);
        }
        return res;
    }
};
// @lc code=end

