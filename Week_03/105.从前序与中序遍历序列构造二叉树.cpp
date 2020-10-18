/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int, int> map;
public:


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i =0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return hepler(preorder, inorder, 0, n -1, 0 , n-1);
    }
    TreeNode* hepler(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if(preorder_left > preorder_right) return nullptr;
        // 前序遍历的根节点
        int preorder_root = preorder_left;
        // 中序遍历的根节点
        int inorder_root = map[preorder[preorder_root]];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = hepler(preorder, inorder, preorder_left +1, preorder_left + size_left_subtree, inorder_left, inorder_root -1);
        root ->right = hepler(preorder, inorder, preorder_left +size_left_subtree +1, preorder_right, inorder_root +1, inorder_right);
        return root;
    }
};
// @lc code=end

