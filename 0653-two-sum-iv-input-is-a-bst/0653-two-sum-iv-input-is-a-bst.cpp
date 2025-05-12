/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    
    void inorderTraversal(TreeNode* &root, vector<int> &arr){

        
        if(!root) return ;
        inorderTraversal(root->left,arr);
        arr.push_back(root->val);
        inorderTraversal(root->right,arr);
    }

    bool checkTwoSum(vector<int> &arr, int target){
        int l =0; 
        int r = arr.size() -1;

        while(l<r){

            int sum = arr[l] + arr[r];
            if(sum == target){
                return true;
            }
            if(sum> target){
                r--;

            }
            if(sum< target){
                l++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorderTraversal(root, arr);
        bool ans = checkTwoSum(arr,k);
        return ans;
    }
};