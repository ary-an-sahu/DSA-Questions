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
    // create child to parent mapping
    void mapParent(TreeNode* root, unordered_map<TreeNode* , TreeNode*>&parentMap){
        if(!root) return;

        if(root->left){
            parentMap[root->left] = root;
            mapParent(root->left, parentMap);
        }

        if(root->right){
            parentMap[root->right] = root;
            mapParent(root->right, parentMap);
        }
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = nullptr;
        mapParent(root,parentMap);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;


        int currLevel = 0;
        while(!q.empty()){
            int size= q.size();
            if(currLevel == k) break;

            currLevel++;

            for(int i=0; i<size; i++){
                auto  front = q.front();
                q.pop();

                if(front->left && visited.find(front->left) == visited.end()){
                    //front has its left children , and it is not yet visited.
                    q.push(front->left);
                    visited[front->left] = true; 
                }

                if(front->right && visited.find(front->right) == visited.end()){
                    //front has its right children , and it is not yet visited.
                    q.push(front->right);
                    visited[front->right] = true; 
                }

                // new thing here have to process parent too.
                auto parentNodeOfFront = parentMap[front];

                if( parentNodeOfFront && visited.find(parentNodeOfFront) == visited.end()){
                    //front has its right children , and it is not yet visited.
                    q.push(parentNodeOfFront);
                    visited[parentNodeOfFront] = true; 
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;


    }
};