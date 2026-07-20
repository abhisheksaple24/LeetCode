class Solution {
public:

    void allcombin(vector<int> arr, int idx, vector<int> &combin, vector<vector<int>> &ans, int tar) {

        int n = arr.size();

        // ans
        if(tar == 0) {
            ans.push_back(combin);
            return;
        }

        // Invalid path
        if(idx == n || tar < 0) {
            return;
        }

        // Include
        combin.push_back(arr[idx]);

        //multiple 
        allcombin(arr, idx, combin, ans, tar - arr[idx]);

        // Backtrack
        combin.pop_back();

        // Not include
        allcombin(arr, idx + 1, combin, ans, tar);
    }


    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {

        vector<vector<int>> ans;
        vector<int> combin;

        allcombin(arr, 0, combin, ans, tar);

        return ans;
    }
};