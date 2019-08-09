class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        helper(n, res, vec, 0, k);
        return res;
    }
   void helper(int n, vector<vector<int>>& res, vector<int>& path, int start, int remain) {

        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < n; i++) {
            path.push_back(i+1);
            helper(n, res, path, i + 1, remain - 1);
            path.pop_back();
        }
    }
};