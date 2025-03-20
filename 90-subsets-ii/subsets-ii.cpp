class Solution {
public:
    void generateSubset(int idx, vector<int>& nums, vector<int>& ans, vector<vector<int>>& sol) {
        if (idx >= nums.size()) {
            sol.push_back(ans);
            return;
        }
        // Include current element
        ans.push_back(nums[idx]);
        generateSubset(idx + 1, nums, ans, sol);
        // Exclude and skip duplicates
        ans.pop_back();
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        generateSubset(idx + 1, nums, ans, sol);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> ans;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        generateSubset(0, nums, ans, sol);
        return sol;
    }
};