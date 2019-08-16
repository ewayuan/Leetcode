class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return is_symmetric(root->left, root->right);
    }
    bool is_symmetric(TreeNode* left, TreeNode* right ) {
        
        if (left == NULL && right == NULL) return true;
        if (left == NULL && right != NULL) return false;
        if (left != NULL && right == NULL) return false;
        if (left->val != right->val) return false;
        
        return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
    }
};
