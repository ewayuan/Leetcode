class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int n = nums.size();
        vector <int> visited(n, 0);
        int target = sum / k;
        return helper(nums, visited, target, 0, k);
    }
    
    bool helper(vector<int>& nums, vector<int>& visited, int target, int pre_sum, int k) {
        if (k == 1) return true;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!visited[i]){
                int cur = pre_sum + nums[i];
                if (cur > target) break;
                visited[i] = 1;
                if (cur == target && helper(nums, visited, target, 0, k-1)) return true;
                else if (helper(nums, visited, target, cur, k)) return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};