class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int ind = -1; //ind to store break point index
        int n = nums.size();

        

        for(int i= n-2 ; i>=0 ; i--){

            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        //if no break point index is found then just reverse array 
        // that will be your answer

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;

        }

        //to find the correct prefix element for the next permutation

        for(int i = n-1 ; i>ind ; i--){

            if(nums[i] > nums[ind]){

                swap(nums[i], nums[ind]);
                break;
            }
        }


        //now for remaining numbers we just need to reverse.

        reverse(nums.begin() + ind + 1 , nums.end());
        

    }
};