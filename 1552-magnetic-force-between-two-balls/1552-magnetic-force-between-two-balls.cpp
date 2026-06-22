class Solution {
public:

    bool isvalid(vector<int> &arr, int c, int n, int mindist) {

        int balls = 1;
        int lastPos = arr[0];

        for(int i = 1; i < n; i++) {

            if(arr[i] - lastPos >= mindist) {
                balls++;
                lastPos = arr[i];
            }

            if(balls == c) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        int n = position.size();

        sort(position.begin(), position.end());

        int st = 1;
        int end = position[n - 1] - position[0];

        int ans = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isvalid(position, m, n, mid)) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};