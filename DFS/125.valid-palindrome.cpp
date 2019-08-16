/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {

        string one_string = "";
        
        for (char x: s) {
            if (isalpha(x) || isdigit(x))
                one_string += tolower(x);
        }
        if (one_string.empty()) return true;
        if (one_string.size() == 1) return true;

        //cout << one_string << endl;
        for (int i = 0; i < one_string.size()-1; i++) {
            if (one_string[i] != one_string[one_string.size()-i-1]) {
                
                return false;
            }
        }
        return true;
    }
};

