class ResultType {
public:
    int sum, size;
    ResultType():sum(0), size(0) {}
    ResultType(int _sum, int _size): sum(_sum), size(_size) {}
};

     
class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode* node = NULL;
    ResultType data;

    
    ResultType helper(TreeNode* root) {
        if (root == NULL) {
            return ResultType();
        }
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        ResultType res = ResultType(left.sum + right.sum + root->val, 
                                    left.size + right.size + 1);
        
        if (node == NULL || res.sum * data.size >= data.sum * res.size) {
            data = res;
            node = root;
        }
        return res;
    }
    
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        helper(root);
        return node;
    }
};