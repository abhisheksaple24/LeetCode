class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check every row
        for(int row = 0; row < 9; row++) {

            bool seen[10] = {false};

            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.')
                    continue;

                int num = board[row][col] - '0';

                if(seen[num])
                    return false;

                seen[num] = true;
            }
        }


        // Check every column
        for(int col = 0; col < 9; col++) {

            bool seen[10] = {false};

            for(int row = 0; row < 9; row++) {

                if(board[row][col] == '.')
                    continue;

                int num = board[row][col] - '0';

                if(seen[num])
                    return false;

                seen[num] = true;
            }
        }


        // Check every 3x3 box
        for(int startRow = 0; startRow < 9; startRow += 3) {

            for(int startCol = 0; startCol < 9; startCol += 3) {

                bool seen[10] = {false};

                for(int row = startRow; row < startRow + 3; row++) {

                    for(int col = startCol; col < startCol + 3; col++) {

                        if(board[row][col] == '.')
                            continue;

                        int num = board[row][col] - '0';

                        if(seen[num])
                            return false;

                        seen[num] = true;
                    }
                }
            }
        }

        return true;
    }
};