class Solution {
public:

    bool isSafe(char digit ,int row ,int col ,vector<vector<char>>&board){
        //3 rule
        //rowCheck

        int n = board.size();

        for(int k=0;k< n;k++){
            if(board[row][k]==digit){
                //same digit pehle se same row me exist karta hai 
                return false;

            }

            //colcheck-

            for(int k=0;k<n; k++){
                if(board[k][col]==digit){
                    //same digit phele se same col me exist krta hai 
                    return false;
                }
            }

            // 3*3 sub box check krna baki hai abb
            for(int k=0;k<n;k++){
                if(board[3*(row/3)+k/3][3*(col/3)+k%3]==digit){
                    //same 3*3 k box me same digit exist karta hai 
                    return false;
                }
            }

        }
        //agar teeno rule acche se follow ho gya then 
        return true;

    }

    bool solve(vector<vector<char>>& board){
        //sabse phle find the empty cell-
        //empty case "."
        for(int i=0;i<board.size();i++){
            for(int j=0;j< board[0].size();j++){
                if(board[i][j] == '.'){
                    //fill this cause its empty
                    //empty cell 1-9
                    for(char digit = '1';digit <='9';digit++){
                        //mujhe pta karna hai ki koun  sa digit rakna safe hai 
                        if(isSafe(digit,i,j,board) == true){
                            //agar safe toh rakho
                            board[i][j] = digit;
                            //baki recursion sambhalega

                            bool aageSolveHoPaya = solve(board);
                            if(aageSolveHoPaya== true){
                                //pura board solve ho gya hai
                                return true;
                            }

                            else{
                                board[i][j] = '.';
                            }
                        }
                    }

                    // 1-9 koi digit fill nhi ho paya
                    return false;
                }
            }
        }
        //pura board completely fill ho gya hai
        // ans aa chuka hai
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};