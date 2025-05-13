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

    TreeNode* solve(vector<int> & inorder, int s, int e){
        if(s> e){
            return NULL;
        }

        int m = (s+e)/2;
        int element = inorder[m];
        TreeNode* root = new TreeNode(element);
        
        root->left = solve(inorder,s,m-1);
        root->right = solve(inorder, m+1 , e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& inorder) {
        int s =0;
        int n = inorder.size();
        int e = n-1;
        int m = (s+e)/2;

        TreeNode* root = solve(inorder, s ,e);
        return root; 
    }
};