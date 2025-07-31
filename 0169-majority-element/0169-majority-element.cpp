class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // unordered_map<int,int> mp; -> better way
      
        // int ans = -1;

        // for(int i=0; i<nums.size();i++){
        //     mp[nums[i]]++;
        // }

        // for(auto it: mp){
        //     if(it.second > nums.size()/2 ){
        //         ans = it.first;
        //     }
        // }
        // return ans;

        // Moore's voting algorithm - optimal way

        int cnt =0;
        int el;

        for(int i=0; i<nums.size();i++){
            if(cnt == 0){
                cnt =1;
                el = nums[i];
            }
            else if(nums[i]== el){
                cnt++;
            }
            else{
                cnt--;
            }

        }

        int cnt1 =0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]== el){
                cnt1++;
            }

            if(cnt1 > (nums.size()/2)){
                return el;
            }
        }

        return -1;
         
    }

};