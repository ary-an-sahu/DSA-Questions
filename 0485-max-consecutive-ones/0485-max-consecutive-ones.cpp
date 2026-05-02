class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int consCnt = 0;
        for(int i =0 ; i<nums.size(); i++){

            if(nums[i] == 1){
                consCnt++;
                maxCnt= max(maxCnt, consCnt);
            }
            else{
                
                consCnt = 0;
            }
        }

        return maxCnt;
    }
};