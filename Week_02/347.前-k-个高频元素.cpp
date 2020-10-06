/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> maps;
        for(auto num :nums) maps[num]++;
        for(auto m :maps) {
            pq.push({m.second, m.first});
            while(pq.size()>k) pq.pop();
        }
        
        vector<int> res;
        while(pq.size() > 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

