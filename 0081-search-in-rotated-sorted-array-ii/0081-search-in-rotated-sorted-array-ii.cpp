class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int low =0;
        int high = nums.size()-1;

        while(low<= high){
            int mid = low+(high- low)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low = low +1;
                high = high-1;
                continue;
            }

            if(nums[low] <= nums[mid]){
                //left hmra sorted hai

                if(nums[low] <= target && nums[mid] >= target){
                    //right part ko trim kr do 
                    high = mid-1;
                }else{
                    //left part me nhi h
                    //left part ko trim kro

                    low =  mid+1;
                }
            }
            else{
                //right part sorted hai

                if(nums[mid] <= target && nums[high] >= target){
                    //right part me element ho skta hai
                    low = mid +1;
                }
                else{
                    //left partt me hjai toh right ko trim kr do
                    high = mid -1;
                }
            }
        }
        return false;
       
    }
};