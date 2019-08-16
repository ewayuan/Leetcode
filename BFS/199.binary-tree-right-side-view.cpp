/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> results;
        queue <TreeNode*> q;
        int Last = 0;
        if (root != NULL) {
            q.push(root);
        }

        while(!q.empty()) {
            queue <TreeNode*> q2;
            while(!q.empty()) {
                TreeNode* top = q.front();
                q.pop();
                if (top == q.back()) {
                    Last = top->val;
                }
                if (top->left != NULL) q2.push(top->left);
                if (top->right != NULL) q2.push(top->right);
            }
            results.push_back(Last);
            q = q2;
        }
        return results;
    }
};

