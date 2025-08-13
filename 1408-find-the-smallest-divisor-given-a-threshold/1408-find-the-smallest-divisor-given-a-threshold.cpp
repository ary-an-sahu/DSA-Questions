class Solution {
public:


    bool possible(vector<int>& nums, int k ,int threshold){
        int cnt =0;

        for(int i=0; i<nums.size();i++){

            cnt += ceil(double(nums[i])/double(k));
        }
        return cnt<=threshold;
    }



    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = -1;


        while(l<=h){
            int mid = (l+h)/2;

            if(possible(nums,mid,threshold)){
                ans = mid;
                h = mid -1;
            }else{
                l = mid +1;
            }
        }

        return ans;
    }
};