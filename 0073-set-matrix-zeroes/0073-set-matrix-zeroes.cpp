class Solution {
public:

    void makeZero(vector<vector<int>>&matrix , int i , int j){
        
        int r = matrix.size();
        int c = matrix[0].size();

        
        //make row zero
        for(int k = 0 ; k<c ; k++){

            matrix[i][k] = 0;
        }

        //make column zero

        for(int k = 0; k<r ; k++){

            matrix[k][j] = 0;
        }
        
    }

    void setZeroes(vector<vector<int>>& matrix) {

        set<pair<int,int>>st;
        int r = matrix.size();
        int c = matrix[0].size();

        if(r == 0 && c == 0){
            return;
        }


        for(int i=0; i<r ; i++){

            for(int j = 0 ; j<c ; j++){

                if(matrix[i][j] == 0){
                    st.insert({i,j});
                }
            }
        }

        for(auto it: st){

            makeZero(matrix,it.first, it.second);
        }
        


        
    }
};