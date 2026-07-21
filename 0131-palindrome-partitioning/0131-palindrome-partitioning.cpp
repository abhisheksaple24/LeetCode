class Solution {
public:

    bool ispalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s2 == s;
    }


    void allparts(string s, vector<vector<string>>& ans, vector<string>& partitions) {

        // Base case
        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        int n = s.size();

        for(int i = 0; i < n; i++) {

            string part = s.substr(0, i + 1);

            if(ispalin(part)) {

                // Choose
                partitions.push_back(part);

                // Recursive call for remaining string
                allparts(s.substr(i + 1), ans, partitions);

                // Backtrack
                partitions.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partitions;

        allparts(s, ans, partitions);

        return ans;
    }
};