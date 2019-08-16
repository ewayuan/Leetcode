/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int max_sum = INT_MIN;
        maxBranchSum(root, max_sum);
        return max_sum;
    }

    int maxBranchSum(TreeNode* root, int& max_sum) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = maxBranchSum(root->left, max_sum);
        int rightSum = maxBranchSum(root->right, max_sum);

        // 1.    5     2.   5     3.   5     4.     5
        //      / \        / \        / \          / \
        //     4   8      -4  8      4   -8      -4  -8
        

        // BranchSum be the max sum from left subtree or right subtree to the root
        // case 2.   BranchSum = root->val + rightSum
        // case 3.   BranchSum = root->val + leftSum
        // case 4.   BranchSum = root->val + 0
        int BranchSum = root->val + max(0, max(leftSum, rightSum));
        
        // max_sum be the maximum path sum
        // max_sum is alternative original max_sum or the max value of BranchSum or root->val + leftSum + rightSum

        // case 1. root->val + leftSum + rightSum
        
        max_sum = max(max_sum, max(BranchSum, root->val + leftSum + rightSum));
        return BranchSum;
    }
};

