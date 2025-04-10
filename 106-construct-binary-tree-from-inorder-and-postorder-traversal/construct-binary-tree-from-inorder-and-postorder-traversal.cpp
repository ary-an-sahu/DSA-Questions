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

    void createMapping(unordered_map<int,int>&valMap ,vector<int>& inorder  ){

        for(int i=0; i<inorder.size(); i++){
            int element =  inorder[i];
            int index =i;
            valMap[element] = index;
        }
    }

    TreeNode* constructTree(unordered_map<int,int>&valMap, vector<int>& inorder,vector<int>& postorder, int &postorderIndex, int inorderStart, int inorderEnd){

        //base case - 
        if(postorderIndex<0){
            return NULL;
        }

        if(inorderStart > inorderEnd){
            return NULL;
        }

        //step 1: postOrder ke last element ko root 
        
        int element = postorder[postorderIndex];
        postorderIndex --;
        TreeNode* root = new TreeNode(element);

        //step 2: right and left call ko pass kro after searching root element in inorder array

        int index = valMap[element];

        //inorderLeft -> inorderStart to index-1;
        //inorderRight -> index +1 to inorderEnd;
        //right part phle - imp.
        root->right = constructTree(valMap ,inorder, postorder, postorderIndex,index+1,inorderEnd );

        //left part baad me - imp.  
        root->left = constructTree(valMap ,inorder, postorder, postorderIndex,inorderStart, index-1 );

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        unordered_map<int,int> valMap;
        createMapping(valMap, inorder);


        TreeNode* root = constructTree(valMap, inorder, postorder, postorderIndex, inorderStart, inorderEnd);

        return root;
    }
};