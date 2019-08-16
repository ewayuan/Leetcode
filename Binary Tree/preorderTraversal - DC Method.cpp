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
    vector<int> preorderTraversal(TreeNode * root) {
        
        vector <int> results;
        
        if (root == NULL) {
            return results;
        }

        // Divide
        vector <int> left = preorderTraversal(root->left);
        vector <int> right = preorderTraversal(root->right);
        
       	// Conquer
        results.push_back(root->val);
        for(auto i : left)
            results.push_back(i);
        for(auto i : right)
            results.push_back(i);

        
        return results;
        
    }
};