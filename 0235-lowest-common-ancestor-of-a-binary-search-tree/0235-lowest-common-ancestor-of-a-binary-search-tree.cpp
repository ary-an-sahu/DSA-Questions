/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return 0;

        //p and q are on left side-
        if(p->val < root->val && q->val < root->val){

            TreeNode* leftAns = lowestCommonAncestor(root->left, p ,q);
            if(leftAns!= NULL){
                return leftAns;
            }
        }

        //p and q are on right side-
        if(p->val > root->val && q->val > root->val){

            TreeNode* rightAns = lowestCommonAncestor(root->right, p ,q);
            if(rightAns!= NULL){
                return rightAns;
            }
        }

        //1st - p on left side and q on right side
        //2nd - q on left side and p on right side
        return root;

    }
};