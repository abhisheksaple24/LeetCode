class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig)
                return false;
        }

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig)
                return false;
        }

        // Check 3x3 grid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {
                if(board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        // Base Case
        if(row == 9)
            return true;

        // Calculate next cell
        int nextRow = row;
        int nextCol = col + 1;

        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Skip filled cells
        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits 1 to 9
        for(char dig = '1'; dig <= '9'; dig++) {

            if(isSafe(board, row, col, dig)) {

                board[row][col] = dig;

                if(helper(board, nextRow, nextCol))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};