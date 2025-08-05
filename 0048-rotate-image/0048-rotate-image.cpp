class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>copy;

        int r = matrix.size();
        int c = matrix[0].size();

        for(int i=0; i<c; i++){
            for(int j=r-1; j>=0 ; j--){
                copy.push_back(matrix[j][i]);
            }
        }

        int k=0;
        for(int i=0; i< r; i++){
            for(int j=0; j<c; j++){
                matrix[i][j] = copy[k];
                k++;
            }
        }
    }
};