/*
http://www.lintcode.com/en/problem/binary-tree-paths/
http://www.jiuzhang.com/solutions/binary-tree-paths/
*/

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> paths;
        // 1. 递归的出口
        if (root == NULL) {
            return vector<string>{};
        }
        
        if (root->left == NULL && root->right == NULL) {
            return vector<string>{to_string(root->val)};
        }
        
        // 2. 递归的拆解
        
        vector <string> left_paths = binaryTreePaths(root->left);
        vector <string> right_paths = binaryTreePaths(root->right);
        
        for (auto i: left_paths) {
            paths.push_back(to_string(root->val) + "->" + i);
        }
        for (auto i: right_paths) {
            paths.push_back(to_string(root->val) + "->" + i);
        }
        return paths;
    }
};