/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
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
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    int depth (TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        return max(leftDepth, rightDepth) + 1;
    }
};

