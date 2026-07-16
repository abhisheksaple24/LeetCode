class Solution {
public:

    void allpermutation(vector<int> nums, int idx, vector<vector<int>> &ans) {

        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            allpermutation(nums, idx + 1, ans);

            // backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> allpermutations;

        allpermutation(nums, 0, allpermutations);

        return allpermutations;
    }
};