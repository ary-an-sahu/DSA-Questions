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

    // isse levelorder se hi kr rhe hai
    bool solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;


        while( !q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                nullFound = true;
            }

            else{
                //valid node ho skta hai front 
                if(nullFound == true){
                    //not a complete binary tree
                    return false;
                }
                else{
                    //may be a cbt , proceed futher
                    q.push(front->left);
                    q.push(front->right);

                }
            }
        }
        return true;
    }

    // Read note 
    bool isCompleteTree(TreeNode* root) {
        bool ans = solve(root);
        return ans;
    }
};