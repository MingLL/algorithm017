/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});
        while(!queue.empty()) {
            if(queue.front().first == endWord) {
                return queue.front().second;
            }
            string temp = queue.front().first;
            int step = queue.front().second;
            queue.pop();
            for(int i = 0; i < temp.size(); i++) {
                char ch = temp[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if(set.find(temp) != set.end()) {
                        queue.push({temp, step +1});
                        set.erase(temp);
                    }
                    temp[i] = ch;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

