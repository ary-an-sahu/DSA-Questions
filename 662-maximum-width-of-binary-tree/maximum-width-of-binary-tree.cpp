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
        unsigned long long maxWidth = 0;

        if(!root) return maxWidth;

        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});

        while(!q.empty()){
            unsigned long long size = q.size();
            unsigned long long leftMostNodeIndex = q.front().second;
            unsigned long long rightMostNodeIndex = q.back().second;
            unsigned long long currentLevelWidth = rightMostNodeIndex- leftMostNodeIndex +1;
            maxWidth = max(maxWidth,currentLevelWidth);

            //traverse over all nodes  at the current level-
            for(unsigned long long i=0;i<size ;i++){
                auto front = q.front();
                q.pop();
                auto node = front.first;
                auto index = front.second;
                
                // process its child and assign them the index
                if(node->left){
                    q.push({node->left, 2*index});
                }


                if(node->right){
                    q.push({node->right, 2*index +1});
                }
            }
        }

        return maxWidth;

    }
};