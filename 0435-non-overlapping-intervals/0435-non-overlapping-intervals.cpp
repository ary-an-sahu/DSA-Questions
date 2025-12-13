class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if(n == 0) return 0;

   
        sort(intervals.begin(),intervals.end());
        vector<int>sub = intervals[0];


        int cnt =0;
        for(int i=1; i<n; i++){

            if(intervals[i][0] < sub[1]){
                cnt++;
                sub[1] = min(sub[1],intervals[i][1]);
                
            }else{
                sub = intervals[i];
            }

        }

        return cnt;
    }
};