/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        if (row == 0 || col == 0) return false;
        vector <vector <bool> > visited(row, vector<bool> (col, 0));
        for (int i = 0; i < row ; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false; 
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string word, int index, vector <vector <bool>>& visited) {
        if(index == word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y] == 1 || board[x][y] != word[index]) {
            return false;
        }

        if (!visited[x][y] && board[x][y] == word[index]) {
            visited[x][y] = true;
            if (dfs(board, x+1, y, word, index+1, visited)) {
                return true;
            }
            if (dfs(board, x-1, y, word, index+1, visited)){
                return true;
            }
            if (dfs(board, x, y+1, word, index+1, visited)) {
                return true;
            }
            if (dfs(board, x, y-1, word, index+1, visited)) {
                return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
};

