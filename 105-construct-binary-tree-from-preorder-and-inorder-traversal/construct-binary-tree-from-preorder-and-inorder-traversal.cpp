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

    int indexOfElementInInorder(vector<int> &inorder, int target){
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == target){
                return i;
            }
        }

        return -1;

    }



    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inOrderStart, int inOrderEnd , int size){

        //base case - 
        if(preOrderIndex >= size){
            return NULL;
        }

        if(inOrderStart > inOrderEnd){
            return NULL;
        }

        //process first element of preOrder as root node of tree 
        //step 1: 
        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);

        //step 2 - find the element in inorder and call its left and right
        int  elementIndexInorder =  indexOfElementInInorder(inorder, element);

        //left part Index -> inOrderStart to elementIndexInorder-1 tak 
        //right part indexes -> elementIndexInorder+1  to  inOrderEnd

        root->left = constructTree(preorder, inorder,preOrderIndex, inOrderStart, elementIndexInorder-1,size);
        root->right = constructTree(preorder, inorder,preOrderIndex,  elementIndexInorder+1, inOrderEnd,size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex =0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size()-1;
        int size = inorder.size();
        TreeNode* root = constructTree(preorder, inorder, preOrderIndex, inOrderStart, inOrderEnd , size);

        return root;
    }
};