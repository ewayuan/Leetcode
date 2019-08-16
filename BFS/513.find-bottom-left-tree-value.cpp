/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode*> q;
        
        int mostLeftVal;
        if (root != NULL) {
            q.push(root);
        }
        while(!q.empty()) {
            vector <int> cur;
            queue <TreeNode*> q2;
            bool isFirstVal = true;
            while(!q.empty()) {
    
                TreeNode* top = q.front();
                q.pop();

                if (isFirstVal) {
                    mostLeftVal = top->val;
                    isFirstVal = false;
                }
                isFirstVal = false;
                if (top->left != NULL) q2.push(top->left);
                if (top->right != NULL) q2.push(top->right);


            }

            q = q2;
        }
        return mostLeftVal;
    }
};

