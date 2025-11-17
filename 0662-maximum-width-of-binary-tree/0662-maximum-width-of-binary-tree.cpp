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
    int widthOfBinaryTree(TreeNode* root) {
        
        long long ans = 0;
        if(root == NULL) return ans;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            long long mini = q.front().second;
            long long first , last;

            for( int i=0; i< size ; i++){

                long long curr_ind = q.front().second - mini ;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = curr_ind;
                if(i == size-1) last = curr_ind;

                if(node->left){
                    q.push({node->left, 2*curr_ind+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_ind +2});
                }

            }

            ans = max(ans,last-first+1);

        }

        return ans;
    }
};