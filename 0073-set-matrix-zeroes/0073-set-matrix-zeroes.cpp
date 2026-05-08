class Solution {
public:
    
    //additional pair is required for this approach ->better solution 
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(); //rows
        int c = matrix[0].size(); //columns

        vector<pair<int , int>> store;

        for(int i=0; i<r ;i++){
            for(int j =0; j<c ; j++){
                if(matrix[i][j] == 0){
                    store.push_back({i,j});
                }

            }

        }

        for(auto it: store){

            int i= it.first;
            int j = it.second;

            for(int m =0; m<c; m++){
                matrix[i][m] = 0;

            }
            for(int n =0; n<r ; n++){
                matrix[n][j] = 0;
            }
        }


    }
};