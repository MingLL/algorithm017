/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i <size; i++) {
                Node *n = q.front();
                q.pop();
                int csize = n->children.size();
                for(int j =0; j<csize; j++) {
                    q.push(n->children[j]);
                }
                temp.push_back(n->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

