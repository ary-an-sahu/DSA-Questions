class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
       
        int ans = INT_MIN;
        int l = -1;
        int m = -1;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                if(mat[i][j] > ans){
                    ans = mat[i][j];
                    l = i;
                    m = j;
                }
            }

        }

        return {l,m};
    }
};