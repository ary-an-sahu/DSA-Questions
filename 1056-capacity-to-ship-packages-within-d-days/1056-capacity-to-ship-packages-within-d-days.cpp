class Solution {
public:

    bool possible(vector<int>& weights, int mid, int days){

        int sum =0;
        int curr_days=1;
        for(int i=0; i<weights.size();i++){
            sum += weights[i];
            if(sum>mid){

               

                curr_days ++;
                sum =weights[i];
            }
           
        }
        

        return curr_days<= days;
    }
        


    int shipWithinDays(vector<int>& weights, int days) {
        int totalW = 0;
        
        int maxW = *max_element(weights.begin(), weights.end());

        for(int i=0; i<weights.size();i++){
            totalW+= weights[i];
        }

        int l = maxW;
        int h = totalW;
        int ans = h;

        while(l<=h){
            int mid = (l+h)/2;

            if(possible(weights,mid, days)){
                ans = mid;
                h = mid -1;

            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};