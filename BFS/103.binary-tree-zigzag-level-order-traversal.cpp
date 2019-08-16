/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> results;
        queue <TreeNode*> q;    
        bool isEvenLevel = false;

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
            if (isEvenLevel) {
                reverse(cur.begin(), cur.end());
            }
            results.push_back(cur);
            isEvenLevel = !isEvenLevel;
            q = q2;
        }
        return results;
    }
};

