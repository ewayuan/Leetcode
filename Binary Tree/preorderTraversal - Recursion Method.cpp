/*
Preorder:
• http://www.lintcode.com/problem/binary-tree-preorder-traversal/
• http://www.jiuzhang.com/solutions/binary-tree-preorder-traversal/
*/

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    void traverse(vector<int>& results, TreeNode* root) {

        // 递归出口
        if (root == NULL) return;
        
        // 递归定义
        results.push_back(root->val);
        
        //递归拆解
        traverse(results,root->left);
        traverse(results,root->right);
    }
    
    
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        vector <int> results;
        traverse(results, root);
        return results;
    }
};