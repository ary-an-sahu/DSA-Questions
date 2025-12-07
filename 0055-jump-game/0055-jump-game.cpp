class Solution {
public:
    bool canJump(vector<int>& nums) {

        // If only one element → you're already at last index
        if (nums.size() == 1) return true;

        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // If we cannot reach index i
            if (maxi < i) return false;

            // Update max reach
            maxi = max(maxi, i + nums[i]);
        }

        return true;
    }
};
