class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if(nums.size() == 0){
            return;
        }

        
        vector<int>store;
        vector<int>cnt0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]== 0){
                cnt0.push_back(nums[i]);
            }

            else{
                store.push_back(nums[i]);
            }
        }


        for(int j = 0; j<cnt0.size() ; j++){

            store.push_back(cnt0[j]);
        }


        for(int k = 0; k< store.size() ; k++){

            nums[k] = store[k];
        }



        


    }
};