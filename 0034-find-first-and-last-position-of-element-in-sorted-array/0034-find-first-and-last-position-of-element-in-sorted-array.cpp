class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sIndex = -1;
        int eIndex = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                if(sIndex == -1){
                    sIndex = i;
                }
                eIndex = i;
            }
        }

        return {sIndex, eIndex};

    }
};