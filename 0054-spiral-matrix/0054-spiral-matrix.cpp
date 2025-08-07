class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;

        int left  = 0;
        int right = cols-1;
        int top =0;
        int bottom = rows-1;
        int totalCount = rows*cols;
        int count =0;

        //first row ->
        while(count< totalCount){
            for(int i= left; i<= right && count< totalCount; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;

            for(int i=top; i<=bottom && count< totalCount; i++){
           
                ans.push_back(matrix[i][right]);
                count++;
            }
            right -- ;

            for(int i=right; i>=left && count< totalCount; i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            for(int i=bottom ; i>=top && count< totalCount ; i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }

        return ans;

    }
};