class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        // NSLidx NSRidx
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> nslidx(n);
        vector<int> nsridx(n);
        stack<int> st;
        int ans;
        // nsr
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nsridx[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nsridx[st.top()] = n;
            st.pop();
        }

        // nsl
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nslidx[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nslidx[st.top()] = -1;
            st.pop();
        }
        // AREA
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = nums[i] * (nsridx[i] - nslidx[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};