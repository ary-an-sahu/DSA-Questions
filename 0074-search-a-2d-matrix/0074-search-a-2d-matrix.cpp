class Solution {
public:
    bool searchElement(vector<int>&arr , int n , int target){

        int low = 0;
        int high = n -1;

        while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid] == target){
                return true;
            }
            
            if(arr[mid]> target){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool finalAns = false;

        for(int i=0; i<rows; i++){
            bool ans = searchElement(matrix[i], cols ,target );

            finalAns = finalAns || ans;

        }
        return finalAns;
    }
};