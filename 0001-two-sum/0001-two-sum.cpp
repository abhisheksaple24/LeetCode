class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        vector<int> ans;

        unordered_map<int, int> m;

        for(int i = 0; i < arr.size(); i++) {

            int first = arr[i];
            int second = target - first;

            if(m.find(second) != m.end()) {     //found
                ans.push_back(m[second]);
                ans.push_back(i);
                break;
            }
            else {      //not found add to unordered map
                m[first] = i;
            }
        }

        return ans;
    }
};