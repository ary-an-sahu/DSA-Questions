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
    void inorderT(TreeNode* &root, vector<int> &store){
        if(!root) return;
        //LNR

        inorderT(root->left,store);
        store.push_back(root->val);
        inorderT(root->right,store);

    }

    int findDif(vector<int> &store, int ans){
        for(int i=0; i< store.size(); i++){
            if(i+1<store.size()){
                int diff = abs(store[i]-store[i+1]);
                ans = min(ans, diff);
            }
            else{
                break;
            }
            
        }
        return ans;
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> store;
        int ans = INT_MAX;
        inorderT(root, store);
        int finalAns = findDif(store,ans);
        return finalAns;

    }
};