class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    
    int minSum = INT_MAX;
    TreeNode * result = nullptr;
    
    int helper(TreeNode* root) {
          
        
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right =  helper(root->right);
        int sum = left + right + root->val;
        
        if (sum < minSum) {
            minSum = sum;
            result = root;
        }
        return sum;
    }
     
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        helper(root);
        return result;
    }
};