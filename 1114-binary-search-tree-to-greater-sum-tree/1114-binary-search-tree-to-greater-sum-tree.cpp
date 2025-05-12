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

    void inorder(TreeNode* &root, vector<int>&arr){
        if(!root) return ;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    void updateTree(TreeNode* root, vector<int>&arr, int &index){

        if(!root) return ;

        updateTree(root->left, arr, index);
        root->val = arr[index];
        
        index++;
        updateTree(root->right,arr,index);

    }


    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            return root;
        }

        //step1 : store inorder
        vector<int> arr;
        inorder(root, arr);


        //step2 : add the and make sum
        int n = arr.size();
        for(int i = n-1; i>=0 ;i--){
            int currVal = arr[i];
            int nextVal = 0 ;


            if(i+1< n){
                nextVal = arr[i+1];
            }

            int sum = currVal + nextVal;

            arr[i] = sum;
        
        }
        //step3 : replace the values at each node
        int index =0;
        updateTree(root,arr, index);
        return root;
    }
};