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

    TreeNode* buildTree(int min , int max, int &i, vector<int> &preorder){
        if(i>= preorder.size()){
            return nullptr;
        }
        TreeNode* root = nullptr;

        if(preorder[i] > min && preorder[i]< max){
            root = new TreeNode(preorder[i++]);
            root -> left = buildTree(min, root->val, i, preorder);
            root -> right = buildTree(root->val, max, i, preorder);
        }
        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int min = INT_MIN, max = INT_MAX;
        int i=0;
        return buildTree(min , max, i , preorder);

    }
};