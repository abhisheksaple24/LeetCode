class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);     // left nearest elem
        vector<int> right(n, 0);    // right nearest elem

        stack<int> s;

        // left
        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = s.top();
            }

            s.push(i);
        }

        // clear stack
        while(s.size() > 0) {
            s.pop();
        }

        // right
        for(int i = n-1; i >= 0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if(s.empty()) {
                right[i] = n;
            }
            else {
                right[i] = s.top();
            }

            s.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int currarea = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, currarea);
        }

        return ans;
    }
};