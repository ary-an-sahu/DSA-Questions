class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     for(int i=0; i<nums.size();i++){
    //         int cval = nums[i];
    //         for(int j = i+1; j<nums.size();j++){
    //             if(nums[j] == cval){
    //                 return nums[i];
    //             }
                
    //         }
    //     }
    //     return -1;
    // }

    int findDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end());

        for(int i =0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }

};