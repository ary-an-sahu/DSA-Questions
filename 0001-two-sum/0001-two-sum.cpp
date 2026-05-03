class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mpp;
        unordered_map<int,bool>visited;
        
        for(int i=0; i<nums.size();i++){

            mpp[nums[i]]= i;
        }

        for(int i=0; i<nums.size();i++){

            int val = target - nums[i];

            if(mpp.find(val) != mpp.end() && mpp[val] != i ){
                return {i,mpp[val]};
            }
        }

        return {};
    }
};