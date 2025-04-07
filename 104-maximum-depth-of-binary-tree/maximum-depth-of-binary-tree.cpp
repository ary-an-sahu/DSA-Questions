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
    // int f(TreeNode* root, int cnt){
    //     int maxi=0;
    //     if(root==NULL) return cnt;
    //     else{
    //         maxi=max(f(root->left,cnt+1),maxi);
    //         maxi=max(f(root->right,cnt+1),maxi);
    //     }
    //     return maxi;
    // }
    // int maxDepth(TreeNode* root) {
    //     int cnt=1;
    //     return f(root,cnt)-1;  
    // }

    int maxDepth(TreeNode* root){

        //base case - 
        if(root == NULL){
            return 0;
        }

        int leftSubtreeHeight = maxDepth(root->left);
        int rightSubtreeHeight = maxDepth(root->right);
        int maxDepth =  max(leftSubtreeHeight, rightSubtreeHeight);
        int totalDepth = maxDepth+1;
        return totalDepth;
    }
};