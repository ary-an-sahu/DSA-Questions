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
    void inorder(TreeNode* &root, vector<int> & arr){
        if(!root) return ;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

    }


    void update(TreeNode* &root, vector<int> & arr , int &index){
        if(!root) return ;
        
        update(root->left, arr, index);
        root->val = arr[index];
        index++;
        update(root->right, arr, index);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(!root ) return 0;
        //inorder nikal liya 
        vector<int> arr;
        inorder(root, arr);

        //sum ko add krna hai each node of arr
        int n = arr.size();
        for(int i= n-1; i>=0; i--){

            int currVal = arr[i];
            int nextVal = 0;

            if(i+1 < n){
                nextVal = arr[i+1];
            }

            int sum = currVal+ nextVal ;

            arr[i] = sum;
        }

        //updation of summed values at each node of BST
        int index =0;
        update(root,arr, index);

        return root;

    }
};