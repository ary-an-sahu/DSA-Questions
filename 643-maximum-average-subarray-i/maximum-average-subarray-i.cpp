class Solution {
public:

    // double bruteforce(vector<int>& nums, int &k){
    //     // complexity - O(n2)
    //    int maxS = INT_MIN;
    //    int i =0; 
    //    int j = k-1;

    //    while(j<nums.size()){
    //         int sum = 0;
    //         for(int t=i;t<=j; t++ ){
    //             sum+=nums[t];
    //         }
    //         maxS = max(maxS, sum);
    //         i++;
    //         j++;

    //    }
    //    double maxAvg = maxS/(double)k;
    //    return maxAvg;
    // }

    double slidingW(vector<int>& nums, int &k){
       int i =0; 
       int j = k-1;
       int sum =0 ;

       for(int t=0; t<=k-1;t++){
        sum += nums[t];
       }
       int maxSum = sum;
       j++;

       while(j< nums.size()){

        sum = sum - nums[i];
        sum = sum + nums[j];
        i++;
        j++;
        maxSum = max(maxSum, sum);
       }

       double maxAvg = maxSum /(double) k;
       return maxAvg;
    }

    
    double findMaxAverage(vector<int>& nums, int k){

        // return bruteforce(nums,k);
        return slidingW(nums,k);
    }
       
};