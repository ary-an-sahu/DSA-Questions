class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int>mpp;
        int ans = -1;
        for(int i =0 ; i<nums.size(); i++){

            mpp[nums[i]]++;
        }

        for(auto it: mpp){

            if(it.second == 1){
                ans = it.first;
            }
        }


        return ans;
        
    }
};