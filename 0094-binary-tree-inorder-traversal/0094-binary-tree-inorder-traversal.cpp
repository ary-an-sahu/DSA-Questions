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
    // vector<int>ans;
    // void inorder(TreeNode* root){
    //     if(root==nullptr){
    //         return;
    //     }
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     inorder(root);
    //     return ans;
    // }


    // Using Morris traversal -  
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;

        TreeNode* curr = root;
        while(curr){

            //if curr ka left is null then visit it and go right
            if(curr->left == nullptr ){
                ans.push_back(curr->val);
                curr = curr -> right;
            }

            // left node is not null 
            else{
                //find  inorder predecessor
                TreeNode* pred = curr->left;
                while(pred->right!= curr && pred->right){
                    pred = pred -> right;
                }

                // if pred right node is NULL, go left after establishing link from pred to curr;
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr -> left;
                }
                else{
                    // if right node is not null 
                    // left is already visited go right after visiting curr node,while removing the link            
                    pred-> right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return ans;
    }
};