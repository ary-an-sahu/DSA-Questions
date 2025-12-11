class Solution {
public:
    bool canJump(vector<int>& nums) {
        
      
        if (nums.size() == 1) return true;
        
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            
            maxi--; 

            if (maxi < 0) return false;

            // if(nums[i] > maxi){
            //     maxi = nums[i];
            // }

            maxi = max(maxi , nums[i]);
        }

        return true;
    }
};
