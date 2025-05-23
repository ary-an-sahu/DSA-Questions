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
    void inorder(TreeNode* &root, vector<int> &arr){
        if(!root) return ;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    void fillBST(TreeNode* &root,vector<int> &arr, int &index){
        if(!root) return;

        fillBST(root->left, arr,index);
        if(root != NULL){
            root->val = arr[index];
            index++;
        }

        fillBST(root->right, arr, index);

    }


    void recoverTree(TreeNode* root) {
        
        vector<int> arr;
        inorder(root,arr);
        sort(arr.begin(), arr.end());

        int index =0;
        fillBST(root,arr, index);
    }
};