/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_map, TreeNode* target){

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            TreeNode* current = q.front();
            q.pop();

            if(current->left){

                parent_map[current->left] = current;
                q.push(current->left);
            }

            if(current->right){
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*>parent_map;

        markParent(root,parent_map,target);

        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]= true;
        int curr_level = 0;

        while(!q.empty()){

            int size = q.size();

            if(curr_level == k) break;
            curr_level++;

            for(int i=0; i<size;i++){

                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left]){

                    visited[current->left] = true;
                    q.push(current->left);
                }

                if(current->right && !visited[current->right]){
                    visited[current->right] = true;
                    q.push(current->right);

                }

                if(parent_map[current] && !visited[parent_map[current]]){
                    visited[parent_map[current]] = true;
                    q.push(parent_map[current]);
                }                    
            }

        }

        vector<int>ans;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            ans.push_back(curr->val);
        }

        return ans;

    }
};