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
    // bool hasPathSum(TreeNode* root, int sum) {
    //     if(!root)return false;                                         //Terminating Condition
    //     sum=sum-root->val;                                             //Body
    //     if(sum==0&&!root->left&&!root->right)return true;              //body
    //     return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);//Propagation
    // }

    bool solve(TreeNode* root, int tar , int sum){
        if(root == NULL){
            return false;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL){ //leaf node pr aa gya
            if(sum == tar){
                return true;
            }
            else{
                return false;
            }
        }

        bool left = solve(root->left, tar, sum);
        bool right = solve(root->right,tar,sum);

        return left || right;
       
    }

    bool hasPathSum(TreeNode* root, int target){

        if(root == NULL ){
            return false;
        }
        int sum = 0;
        
        bool ans = solve(root, target, sum);
        return ans;
        
    }
};