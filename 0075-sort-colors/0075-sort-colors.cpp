class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size() == 0){
            return;
        }

        int zerocnt = 0, onecnt = 0 , twocnt = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == 0){
                zerocnt++;
            }
            else if(nums[i] == 1){
                onecnt++;
            }else{
                twocnt++;
            }
        }
        int i = 0;
        while(zerocnt--){
            nums[i] = 0;
            i++;
        }

        while(onecnt--){
            nums[i] = 1;
            i++;
        }
        
        while(twocnt--){
            nums[i] = 2;
            i++;
        }

        
    }
};