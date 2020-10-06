/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // helper(root, res);
        loop(root, res);
        return res;
    }
    // 递归遍历
    void helper(TreeNode *root, vector<int> &res) {
        if(root == nullptr) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    // 循环遍历
    void loop(TreeNode *root, vector<int> &res) {
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while(root != nullptr) {
                s.push(root);
                root = root -> left;
            }
            TreeNode* n = s.top();
            s.pop();
            res.push_back(n->val);
            root = n->right;
        }
    }
};
// @lc code=end

