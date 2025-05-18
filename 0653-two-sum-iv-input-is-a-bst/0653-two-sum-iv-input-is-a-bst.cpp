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

    bool solve(vector<int> &arr,int k){
        int l = 0;
        int r = arr.size()-1;

        while(l<r){
            int sum = arr[l] + arr[r];

            if(sum == k ){
                return true;
            }
            if(sum < k){
                l++;
            }
            else{
                r--;
            }
        }

        return false;
    }

    void inorder(TreeNode* &root,vector<int> &arr){
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }



    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        bool ans = solve(arr,k);
        return ans;
    }
};