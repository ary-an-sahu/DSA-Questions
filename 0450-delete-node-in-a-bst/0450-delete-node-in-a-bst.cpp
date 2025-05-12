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

    int getMax(TreeNode* root){

        if(!root) return -1;

        while(root->right){
            root = root -> right;
        }

        return root ->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return 0;

        TreeNode* temp = root;
        if(temp->val == key){
            // cases - 
            //with zero child
            if(temp ->left == NULL && temp ->right == NULL){
                delete temp;
                return NULL;
            }
            // with right child only
            if(temp->right!= NULL && temp->left == NULL){
                TreeNode* rightAns = temp->right;
                delete temp;
                return rightAns;
            }
            // with left child only
            if(temp->left!= NULL && temp->right == NULL){
                TreeNode* leftAns = temp->left;
                delete temp;
                return leftAns;
            }
            //with both the children
            if(temp->left != NULL && temp->right != NULL){
                int maxVal =  getMax(root->left);
                root->val = maxVal;

                root->left = deleteNode(temp->left  ,maxVal);
                return root;
            }
        }

        else{
            //not found 
            if( key> temp->val ){
                temp -> right = deleteNode(temp->right,key);
            }
            if( key< temp->val ){
                temp ->left = deleteNode(temp->left,key);
            }
            
        }

        return root;
    }
};