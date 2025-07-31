class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
      
        int ans = -1;

        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            if(it.second > nums.size()/2 ){
                ans = it.first;
            }
        }
        return ans;
    }

};