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


        //slow approach - O(n2) => 

        // int getHeight(TreeNode* root){
        //     if(root== NULL){
        //         return 0;
        //     }

        //     int left = getHeight(root->left);
        //     int right = getHeight(root->right);
        //     int maxH = max(left, right);
        //     int totalH = maxH +1;

        //     return totalH;
        // }
        // bool isBalanced(TreeNode* root) {
            
        //     if(root == NULL){
        //         return true;
        //     }

        //     //ek case hum solve krenge 
        //     int leftSubtreeH = getHeight(root->left);
        //     int rightSubtreeH = getHeight(root->right);
        //     int absDiff = abs(leftSubtreeH - rightSubtreeH);
        //     bool status = absDiff <= 1;

        //     // baaki recursion sambhal lega 
        //     bool leftAns = isBalanced(root->left);
        //     bool rightAns = isBalanced(root->right);

        //     // i can say that whether tree is balancerd or not when?
        //     // curr node balanced
        //     // left subtree balanced
        //     // right subtree balanced


        //     if(status && leftAns && rightAns ){
        //         return true;
        //     }

        //     else{
        //         return false;
        //     }

        // }

        bool isBalancedT = true; //global variable

        int height(TreeNode* root){
            if(root==NULL){
                return 0;
                
            }

            int lh = height(root->left);
            int rh = height(root->right);

            //check for current node is it balanced??
            if(isBalancedT && abs(lh-rh) >1){
                isBalancedT = false;
            }

            return max(lh,rh)+1;

        }

        bool isBalanced(TreeNode* root) {
            height(root);
            return isBalancedT;
        }
    };