class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int>store;
        int n = nums.size();
        int j = 0;
    
        if(k>= n){
            k = k % n ;
        }

        for(int i=0; i<n; i++){

            if(i > abs(n - k - 1) ){
                nums[j] = nums[i];
                j++;
            }
            else{
                store.push_back(nums[i]);
            }
            

        }

        for(int m = 0 ; m < store.size() ; m++){
            nums[j] = store[m];
            j++;
        }

    }
};