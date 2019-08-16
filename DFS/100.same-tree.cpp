/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // case 1. p, q all NULL
        if (p == NULL && q == NULL) return true;
         
        // case 2: 当下(p ！= NULL || q ！= NULL)
        //         但此时可能存在（p == NULL || q == NULL）

        if (p == NULL || q == NULL) return false;
        if (p-> val != q->val) return false;
        if (isSameTree(p->left, q->left) && 
            isSameTree(p->right, q->right)) {
                return true;
            }
        return false;
    }
};

