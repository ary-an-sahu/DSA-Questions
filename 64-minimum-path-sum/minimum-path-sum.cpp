class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> prev(m,-1),curr(m,-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[0]=grid[0][0];
                else{
                    int bottom=INT_MAX,right=INT_MAX;
                    if(i>0)
                        bottom=prev[j];
                    if(j>0)
                        right=curr[j-1];

                    curr[j]=grid[i][j]+min(bottom,right);
                }
            }
            prev=curr;
        }

        return prev[m-1];
    }
};