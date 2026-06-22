class Solution {
public:

    bool isValid(vector<int>& nums, int k, long long maxSum) {

        int subarrays = 1;
        long long currSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > maxSum) {
                return false;
            }

            if(currSum + nums[i] <= maxSum) {
                currSum += nums[i];
            }
            else {
                subarrays++;
                currSum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long sum = 0;

        for(int num : nums) {
            sum += num;
        }

        long long st = 0;
        long long end = sum;
        long long ans = sum;

        while(st <= end) {

            long long mid = st + (end - st) / 2;

            if(isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return (int)ans;
    }
};