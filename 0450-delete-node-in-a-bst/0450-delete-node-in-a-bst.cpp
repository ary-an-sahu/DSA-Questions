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
    int findMax(TreeNode* root){
        if(!root) return -1;

        while(root->right){
            root = root->right;
        }
        return root->val;
    }



    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return 0;
        TreeNode* temp = root;

        if(temp->val == key){
            //if root empty
            if(temp->left == NULL && temp->right == NULL){
                delete temp ;
                return NULL;
            }
            //if right node only present
            if(temp->left == NULL && temp->right != NULL){
                TreeNode* rightAns = temp->right;
                delete temp;
                return rightAns;
            }
            //if left node only present
            if(temp->left != NULL && temp->right == NULL){
                TreeNode* leftAns = temp->left;
                delete temp;
                return leftAns;
            }
            // if both nodes are present 
            if(temp->left != NULL && temp ->right != NULL){
                int maxVal = findMax(root->left);
                root->val = maxVal;

                temp->left = deleteNode(temp->left, maxVal);
            }
        }
        else{
            //key not found 

            if(key> root->val){
                root->right = deleteNode(root->right,key);
            }
            if(key< root->val){
                root->left = deleteNode(root->left,key);
              
            }
        }

        return root;
    }
};