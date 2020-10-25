/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(s.size() < 1 || g.size() <1) return 0;
        int sIndex = s.size() -1;
        int res = 0;
        for(int i = g.size() -1; i >=0; i--) {
            if(g[i] <= s[sIndex]) {
                sIndex--;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

