class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int low = 0, mid = 0, high = nums.size()-1;
    //     while(mid <= high){
    //         if(nums[mid] == 0){
    //             swap(nums[low], nums[mid]);
    //             low++;
    //             mid++;
    //         }
    //         else if(nums[mid] == 1){
    //             mid++;
    //         }
    //         else{
    //             swap(nums[mid], nums[high]);
    //             high--;
    //         }
    //     }
    // }

    void sortColors(vector<int>& nums){
        // 0-> red
        // 1-> green
        // 2-> blue
        int countRed = 0;   
        int countGreen =0;
        int countBlue =0;

        for(int i=0; i<nums.size();i++){
            if(nums[i]==0){
                countRed++;
            }
            else if(nums[i]== 1){
                countGreen++;
            }
            else{
                countBlue++;
            }
        }
        int index = 0;
        while(countRed--){
            nums[index] = 0;
            index++;
        }

        while(countGreen-- ){
            nums[index] = 1;
            index++;
        }

        while(countBlue-- ){
            nums[index] = 2;
            index++;
        }


    }
};