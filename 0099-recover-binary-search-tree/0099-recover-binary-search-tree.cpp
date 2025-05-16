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

    TreeNode* FV=0 ,*SV =0, *prev = 0;// firstviolation , secondviolation
public:
    
    void solve(TreeNode* curr){
        if(!curr) return ;

        //inorder traversal kro
        solve(curr->left);

        if(prev && prev->val > curr->val){

            if(!FV){
                FV = prev;
            }
            SV = curr;
        }
        prev = curr;

        solve(curr->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        if(FV && SV) swap(FV->val , SV->val);

    }
};