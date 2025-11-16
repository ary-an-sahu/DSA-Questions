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
    void solve(TreeNode* root, vector<vector<int>>&ans, bool &leftToRight){

        queue<TreeNode*>q;
        vector<int>level;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){

            TreeNode* top = q.front();
            q.pop();

            if(top == NULL){

                if(leftToRight ==  true){
                    ans.push_back(level);
                }
                else{
                    reverse(level.begin(), level.end());
                    ans.push_back(level);
                }
                level.clear();

                if(!q.empty()){
                    q.push(NULL);
                }

                leftToRight = !leftToRight;



            }

            else{

                level.push_back(top->val);

                if(top->left ) {
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }

        }
    }



    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        bool leftToRight= true;
        solve(root,ans,leftToRight);

        return ans;
    }
};