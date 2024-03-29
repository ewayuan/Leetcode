class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    TreeNode *lastNode = NULL;
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (lastNode != NULL && lastNode->val >= root->val) {
            return false;
        }
        lastNode = root;
        return isValidBST(root->right);
    }

};