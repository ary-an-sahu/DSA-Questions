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
    void traverse(TreeNode* root, vector<int>&store){
        if(root == NULL) return;
        store.push_back(root->val);
        traverse(root->left,store);
        traverse(root->right,store);
    }

    void solve(TreeNode* root, vector<int>&store, int &i){

        if(root == NULL || i >= store.size()){
            return;
        }

        solve(root->left,store,i);

        if(store[i] == root->val){
            i++;
        }else{
            root->val = store[i];
            i++;
        }

        solve(root->right,store,i);
    }

    void recoverTree(TreeNode* root) {


        vector<int>store;
        traverse(root,store);
        sort(store.begin(), store.end());
        int i =0;
        solve(root,store,i);
    }
};