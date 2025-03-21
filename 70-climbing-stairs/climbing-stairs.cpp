class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1; // Base cases: 0 or 1 steps

        vector<int> dp(n + 1, 0); // Create a dp array of size n+1
        dp[0] = 1; // One way to stay at the ground
        dp[1] = 1; // One way to reach the first step

        // Fill the dp array using the recurrence relation
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n]; // The number of ways to reach the n-th step
    }
};