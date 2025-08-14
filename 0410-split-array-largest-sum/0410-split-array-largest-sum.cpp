class Solution {
public:

    int numsSplit(vector<int> &nums, int Lsum){
        int arrS = 1;
        int splitSum = 0;

        for(int i=0; i<nums.size();i++){

            if(splitSum + nums[i] <= Lsum){
                splitSum += nums[i];
            }
            else{
                arrS++;
                splitSum = nums[i];
            }
        }
        return arrS;
    }

    int splitArray(vector<int>& nums, int k) {

        if(k> nums.size() ) return -1;

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);


        while(low<= high){
            int mid = (low+high)/2;

            if(numsSplit(nums,mid)<= k){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }


        return low;

    }
};