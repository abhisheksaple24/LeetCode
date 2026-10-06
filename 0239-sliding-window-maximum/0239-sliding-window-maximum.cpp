class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        // first window
        for(int i = 0; i < k; i++) {

            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // other windows
        for(int i = k; i < n; i++) {

            // remove elements outside window
            while(dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }

            // remove smaller elements
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};