/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector<int>> results;
        queue <TreeNode*> q;    

        if (root != NULL) {
            q.push(root);
        }
        while(!q.empty()) {
            vector <int> cur;
            queue <TreeNode*> q2;
            while (!q.empty()) {
                TreeNode* top = q.front();
                q.pop();
                cur.push_back(top->val);

                if (top->left != NULL) q2.push(top->left);
                if (top->right != NULL) q2.push(top->right);
                
            }
            results.push_back(cur);
            q = q2;
        }
        reverse(results.begin(), results.end());
        return results;
    }
};

