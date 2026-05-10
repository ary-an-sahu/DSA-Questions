class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int i = matrix.size();
        int j = matrix[0].size();

        vector<vector<int>> arr(i, vector<int>(j));


        for(int c = 0; c<j ; c++){

            for(int r = i-1 ; r>=0 ; r--){

                arr[c][i-1-r] = matrix[r][c];
            }
        }

        for(int i=0; i<arr.size(); i++){
            for(int j = 0; j <arr[0].size(); j++){
                matrix[i][j] = arr[i][j];
            }
        }
        
    }
};