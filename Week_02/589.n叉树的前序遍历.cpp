/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr) return res;
        helper(root, res);
        return res;
    }
    // 递归版本
    void helper(Node* root, vector<int> &res){
        if(root == nullptr) return ;
        res.push_back(root->val);
        for(int i =0; i < root->children.size(); i++) {
            helper(root->children[i], res);
        }
    }
    // 循环版本
    void loop(Node* root, vector<int> &res) {
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* temp = s.top();
            s.pop();
            if(temp != nullptr) {
                res.push_back(temp->val);
            } else {
                continue;
            }
            if(!temp->children.empty()) {
                int size = temp->children.size();
                for(int i =0; i< size; i++) {
                    s.push(temp->children[i]);
                }
            }
        }
    }
};


// @lc code=end

