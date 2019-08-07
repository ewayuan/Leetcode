class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int N = nums.size();

        // visited 用来记录array中哪个数字使用过
        vector<int> visited(N, 0);

        vector<vector<int>> results; 
        vector<int> cur;

        permute_fun(nums, 0, cur, results, visited);
        
        return results;
    }
public:
    void permute_fun(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& results,vector<int>& visited) {
        int n = nums.size();
        // 1. 出口
        if (index == n) {
            results.push_back(cur);
            return;
        }
        // 2. 拆解
        for (int i = 0; i < n; i++) {
            // 若当前数字没有使用过，则对其进行recursion
            if (visited[i] == false) {
                visited[i] = 1;
                // recursion
                cur.push_back(nums[i]);
                permute_fun(nums, index + 1, cur, results, visited);
                // backtracking
                cur.pop_back();
                visited[i] = 0;
                    
            }
        }
    }
};