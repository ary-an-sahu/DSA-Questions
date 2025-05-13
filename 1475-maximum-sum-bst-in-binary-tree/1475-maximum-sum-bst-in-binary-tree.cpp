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
class Info{
    public:
    int minVal;
    int maxVal ;
    int sum ;
    bool isBST;
};



class Solution {
public:

    int minCalc(int a  ,int b, int c){
        int minAns = min(a,min(b,c));
        return minAns;
    }

    int maxCalc(int a, int b, int c){
        int maxAns= max(a, max(b,c));
        return maxAns;
    }

    Info solve(TreeNode* root, int &sum ){
        //base case
        if(root == NULL){
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum,temp.sum);
            return temp;
        }

        if(root->left == NULL && root->right == NULL){
            Info temp;
            temp.minVal = root->val;
            temp.maxVal = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum = max(sum,temp.sum);
            return temp;
        }

        //LNR 
        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum );

        //N
        Info currentAns;
        currentAns.minVal = minCalc(leftAns.minVal , rightAns.minVal, root->val);
        currentAns.maxVal = maxCalc(leftAns.maxVal , rightAns.maxVal , root->val);
        currentAns.sum = leftAns.sum + rightAns.sum + root->val;
        currentAns.isBST = (root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST);

        //jab bhi BST milega tabhi uska sum  update kra lunga 
        //iss tarikee se mere pass maxsum aa jayega

        if(currentAns.isBST){
            sum = max(sum,currentAns.sum);
        }

        return currentAns;
    }

    int maxSumBST(TreeNode* root) {
        int sum =0;
        
        Info temp = solve(root, sum);
        return sum;

    }
};