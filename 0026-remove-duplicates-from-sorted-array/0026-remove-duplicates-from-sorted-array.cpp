class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        map<int,int>dups;

        for(int i=0; i<nums.size();i++){

            dups[nums[i]]++;
        }

        int k = dups.size();

        int j = 0;

        for(auto it: dups){
            nums[j] = it.first;
            j++;
        }

        return k;
        
    }
};