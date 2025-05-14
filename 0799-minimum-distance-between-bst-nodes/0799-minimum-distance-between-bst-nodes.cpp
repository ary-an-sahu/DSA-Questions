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

    void solve(TreeNode* root, int &ans , TreeNode* &prev){

        if(!root) return ;
        //LNR 
        solve(root->left,ans , prev);
        
        if(prev){
            int minAns = abs(root->val - prev->val);
            ans = min(ans,minAns);
        }
        prev = root;

        solve(root->right, ans, prev);

        
    }

    int minDiffInBST(TreeNode* root) {
        
        TreeNode* prev  = NULL;
        int ans = INT_MAX;
        solve(root,ans, prev);
        return ans;
    }
};