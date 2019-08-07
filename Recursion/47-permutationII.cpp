class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int N = nums.size();

        // 对nums进行排序，用于去重
        sort(nums.begin(), nums.end());
        vector<int> visited(N, 0);

        vector<vector<int>> results; 
        vector<int> cur;

        permute_fun(nums, 0, cur, results, visited);
        
        return results;
    }
public:
    void permute_fun(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& results,vector<int>& visited) {
        int n = nums.size();
        if (index == n) {
            results.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            // 去重操作， 当当前数字已经visit过，则跳过
            if (visited[i] == true) continue;
            // 去重操作， 当当前数字与前面一个数字相同，并且前面一个数字没有visit，则跳过
            if (i > 0 && nums[i] == nums[i-1] && visited[i-1] == false) {
                continue;
            }
            
            visited[i] = 1;
                
            cur.push_back(nums[i]);
            permute_fun(nums, index + 1, cur, results, visited);
            cur.pop_back();
            visited[i] = 0;

            }
        }
};