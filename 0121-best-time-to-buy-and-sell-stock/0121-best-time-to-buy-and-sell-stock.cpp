class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
    
        int maxP = INT_MIN;

        for(int i = 0; i<prices.size(); i++){

            int profit = prices[i] -  mini;

            maxP = max(maxP, profit);

            mini = min(mini, prices[i]);


        }

        return maxP;
    }
};