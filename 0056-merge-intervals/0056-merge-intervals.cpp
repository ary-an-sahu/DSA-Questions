class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if(n == 0) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> sub = intervals[0];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= sub[1]) {
                sub[1] = max(sub[1], intervals[i][1]);
            } else {
                ans.push_back(sub);
                sub = intervals[i];
            }
        }

        ans.push_back(sub);
        return ans;
    }
};
