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


    // array sorting method - 
    // int findDuplicate(vector<int>& nums){
    //     sort(nums.begin(), nums.end());

    //     for(int i =0; i<nums.size()-1; i++){
    //         if(nums[i] == nums[i+1]){
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }


    // negative index method - 
    int findDuplicate(vector<int>& nums){

        int ans = -1;

        for(int i=0; i< nums.size();i++){

            int index = abs(nums[i]);

            if(nums[index]< 0){
                ans = index;

                break;
            }

            nums[index] *= -1;
        }
        return ans;
    }
};