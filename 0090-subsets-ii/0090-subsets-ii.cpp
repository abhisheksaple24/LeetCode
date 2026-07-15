class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& ans,
               int i,
               vector<vector<int>>& allsubset)
    {
        if (i == nums.size())
        {
            allsubset.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        solve(nums, ans, i + 1, allsubset);

        // Backtrack
        ans.pop_back();

        // Skip duplicates
        int idx = i;
        while (idx < nums.size() - 1 && nums[idx] == nums[idx + 1])
        {
            idx++;
        }

        // Exclude
        solve(nums, ans, idx + 1, allsubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubset;
        vector<int> ans;

        solve(nums, ans, 0, allsubset);

        return allsubset;
    }
};