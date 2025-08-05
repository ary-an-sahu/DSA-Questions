class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int lSmall = INT_MIN;
        int count =0;
        int longest =1;
        
        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());

        for( int i=0; i<nums.size(); i++){

            if(nums[i] - 1 == lSmall){
                count ++;
                lSmall = nums[i];

            }
            if(nums[i] != lSmall){
                count = 1;
                lSmall = nums[i];
            }
            longest = max(longest , count);

        }

        return longest;
    }
};