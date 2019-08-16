/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector <vector<string>> results;
        vector<string> path;
        helper(results, s, 0, path);
        return results;
    }
    void helper(vector <vector<string>>& results, string s, int step, vector<string>& path ) {
        if (step == s.size()) {
            results.push_back(path);
            return;
        }

        // path.push_back(s.substr(step,1));
        // helper(results, s, step + 1, path);
        // path.pop_back();

        for (int i = 1; i + step <= s.size();i++) {
            string sub = s.substr(step, i);
            //cout << "sub: " << sub << endl;
            if (isPalindrome(sub)) {
                path.push_back(sub);
                helper(results, s, i+step, path);
                path.pop_back();
            }
            
        }
    }




      bool isPalindrome(string s){
        int i(0), j(s.size()-1);
        while(i < j) 
            if(s[i++] != s[j--]) return false;
        return true;
    }
};

