class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int cnt = 0;
        int n = r*c ;
        vector<int>ans;

        int top = 0;
        int down = r-1;
        int left = 0;
        int right = c-1;


        while( cnt < n){

            for(int i= left ; i<=right && (cnt< n); i++){
                ans.push_back(matrix[top][i]);
                cnt++;
            }
            top++;

            for(int i = top ; i<=down && (cnt< n); i++){
                ans.push_back(matrix[i][right]);
                cnt++;
            }
            right--;

            for(int i= right; i>= left && (cnt< n) ; i--){
                ans.push_back(matrix[down][i]);
                cnt++;
            }
            down--;

            for(int i = down ; i>= top && (cnt< n) ; i--){
                ans.push_back(matrix[i][left]);
                cnt++;
            }
            left++;

        }


        return ans;
        
    }
};