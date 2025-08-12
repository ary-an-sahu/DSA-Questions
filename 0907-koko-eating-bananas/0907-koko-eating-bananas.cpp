class Solution {
public:

    double findTotal(vector<int>& piles, int hours){

        double count = 0;

        for(int i=0; i<piles.size();i++){
            count = count + ceil(double(piles[i])/double(hours));
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        

        int ans = INT_MAX;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());


        while(low <= high){
            int mid = (low+high)/2;

            double val = findTotal(piles,mid);
            if(val <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};