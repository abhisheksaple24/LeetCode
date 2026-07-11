class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans;
        int a = 0;
        int b = 0;

        unordered_set<int> s;

        int actual_sum = 0;
        int expected_sum = 0;

        int n = grid.size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {

                actual_sum = actual_sum + grid[i][j];

                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                }
                else {
                    s.insert(grid[i][j]);
                }
            }
        }

        expected_sum = (n * n) * (n * n + 1) / 2;

        b = expected_sum + a - actual_sum;

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};