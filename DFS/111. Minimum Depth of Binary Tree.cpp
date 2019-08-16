class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        if (root->left == NULL && root->right != NULL) {
            return 1+minDepth(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            return 1+minDepth(root->left);
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0) {
            right += 1;
        }  else if (right == 0) {
            left += 1;
        }
        return min(left, right) + 1;
    }
};