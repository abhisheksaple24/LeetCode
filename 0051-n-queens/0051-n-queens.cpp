class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {

        // Check same column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueen(vector<string> &board, int row, int n,
                vector<vector<string>> &ans) {

        // Base Case
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column
        for(int j = 0; j < n; j++) {

            if(isSafe(board, row, j, n)) {

                // Place Queen
                board[row][j] = 'Q';

                // Recursive Call
                nQueen(board, row + 1, n, ans);

                // Backtrack
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        nQueen(board, 0, n, ans);

        return ans;
    }
};