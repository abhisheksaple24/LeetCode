class Solution {
public:

    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int exval) {

        // BC
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != exval) {
            return false;
        }

        // Reached last value
        if(exval == n * n - 1) {
            return true;
        }

        bool ans1 = isValid(grid, r-2, c+1, n, exval+1);
        bool ans2 = isValid(grid, r-1, c+2, n, exval+1);
        bool ans3 = isValid(grid, r+1, c+2, n, exval+1);
        bool ans4 = isValid(grid, r+2, c+1, n, exval+1);
        bool ans5 = isValid(grid, r+2, c-1, n, exval+1);
        bool ans6 = isValid(grid, r+1, c-2, n, exval+1);
        bool ans7 = isValid(grid, r-1, c-2, n, exval+1);
        bool ans8 = isValid(grid, r-2, c-1, n, exval+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        if(grid[0][0] != 0)
            return false;

        return isValid(grid, 0, 0, grid.size(), 0);
    }
};