class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        //prefix sum concept
        int n = nums.size();
        int cnt = 0;
        vector<int>prefixSum(n);
        
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        unordered_map<int,int>mpp; // ps, count
        for(int i = 0; i<n ; i++){

            if(prefixSum[i] == k){
                cnt++;
            }

            int val = prefixSum[i] - k;

            if(mpp.find(val) != mpp.end()){
                cnt+= mpp[val];
            }

            if(mpp.find(prefixSum[i]) == mpp.end()){
                mpp[prefixSum[i]] = 0;
            }

            mpp[prefixSum[i]] ++;
        }

        return cnt;
    }
};