/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue <TreeNode*> q;
        q.push(root);
        int min_depth = 1;
        while (!q.empty()) {

            queue <TreeNode*> q2;

            while (!q.empty()) {

                TreeNode* top = q.front();
                q.pop();

                if (top->left == NULL && top->right == NULL) {
                    return min_depth;
                }
                if (top->left != NULL) q2.push(top->left);
                if (top->right != NULL) q2.push(top->right);
            }
            min_depth += 1;
            q = q2;
        }
        return min_depth;
    }
};

