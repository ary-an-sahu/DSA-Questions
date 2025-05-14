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

    bool validate(TreeNode* root, long long lb , long long ub ){
        if(!root) return true;

        bool isCurrentNodeInRange = root->val > lb && root->val < ub;

        bool isLeftBST = validate(root->left, lb, root->val);
        bool isRightBST = validate(root->right, root->val , ub);

        return isCurrentNodeInRange && isLeftBST && isRightBST;
    }
    
    bool isValidBST(TreeNode* root) {
        long long  lb = LONG_MIN;
        long long ub = LONG_MAX;

        return validate(root,lb, ub);

    }
};