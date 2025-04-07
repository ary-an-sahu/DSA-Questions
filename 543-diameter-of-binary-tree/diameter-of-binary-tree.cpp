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
    int getLength(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = getLength(root->left);
        int right =  getLength(root->right);
        int maxLength = max(left, right);
        int totalLength = maxLength +1;
        return totalLength;
        
    }


    int diameterOfBinaryTree(TreeNode* root) {
        //base case - 
        if(root == NULL){
            return 0;
        }

        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = getLength(root->left) + getLength(root->right);

        int maxDia = max(opt1,max(opt2,opt3));

        return maxDia;
    }
};