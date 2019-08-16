class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> results;
        
        if (root == NULL) {
            return results;
        }
        
        // 1. 创建一个队列（Queue）， 把其实节点都放到里面去
        queue<TreeNode *> Q;
        Q.push(root);
        
        // 2. while 队列不空， 处理队列中的节点， 并拓展出新节点
        
        while(!Q.empty()) {
            // for 上一层的节点拓展出下一层的节点
            int size = Q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                level.push_back(node->val);
                if (node->left != NULL) {
                    Q.push(node->left);
                }
                if (node->right != NULL) {
                    Q.push(node->right);
                }
            }
            results.push_back(level);
        }
        return results;
    }
};