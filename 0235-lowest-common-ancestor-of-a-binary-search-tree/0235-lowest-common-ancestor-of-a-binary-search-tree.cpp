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
        if(root == NULL){
            return 0;
        }

        //case 1:  p and q both are left side
        // right-> neglect and q -> select
        if(p->val < root->val && q->val< root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            if(leftAns!= NULL){
                return leftAns;
            }
        }
        

        //case 2:  p and q both are right side
        if(p->val> root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            if(rightAns != NULL){
                return rightAns;
            }
        }



        //case 3:  p in left subtree and q are on different side
        //case 4:  q in left subtree and p are on different side
        return root;
    }
};