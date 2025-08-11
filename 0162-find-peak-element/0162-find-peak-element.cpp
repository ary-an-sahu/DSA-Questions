class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int index = -1;

        for(int i=0; i<nums.size();i++){
            if(nums[i] > maxi){
                maxi = max(maxi, nums[i]);
                index = i;
            }

        }

        return index;

        
    }
};