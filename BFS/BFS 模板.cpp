// Templete for BFS



// 双 queue 法

class Solution {
public:
    vector<vector<int>> **** (TreeNode* root) {
        vector <vector<int>> results;

        queue<TreeNode*> q;

        if (root != NULL) {
            q.push(root);
        }

        // 此 while loop 不是用来处理结果的， 只是用来 “刚才那一级子问题已经是最后一级了， 
        // 并且刚才那一级的子问题没有新的子问题push到queue2中， 则queue2 为空， queue也为空”
        // 用来保证该退出时退出

        while (!q.empty()) {

            // 如果需要处理层与层之间的关系， 在这个while loop

            vector <int> cur;
            queue<TreeNode*> q2;

            // 此 while loop 真正的对于queue中的元素进行遍历，找出第k+1层的子问题

            while (!q.empty()) {

                // 如果需要处理这一层的子问题， 在这个while loop

                TreeNode* top = q.front();
                q.pop();
                cur.push_back(top->val); 
                // ......
                // if (top->left != NULL) {
                //     q2.push(top->left);
                // } 
                // if (top->right != NULL) {
                //     q2.push(top->right);
                // }
                // ......
            }
            results.push_back(cur);
            q = q2;
        }
    return results;
    }
};