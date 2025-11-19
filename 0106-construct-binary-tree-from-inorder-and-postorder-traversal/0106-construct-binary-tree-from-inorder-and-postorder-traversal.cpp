class Solution {
public:
    TreeNode* solve(vector<int>& inorder, int is, int ie,
                    vector<int>& postorder, int ps, int pe,
                    map<int, int>& hashM) {

        if (is > ie || ps > pe)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = hashM[postorder[pe]];
        int numsleft = inRoot - is;

        root->left = solve(inorder, is, inRoot - 1, postorder, ps,
                           ps + numsleft - 1, hashM);

        root->right = solve(inorder, inRoot + 1, ie, postorder, ps + numsleft,
                            pe - 1, hashM);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size() != postorder.size())
            return NULL;

        map<int, int> hashM;

        for (int i = 0; i < inorder.size(); i++) {
            hashM[inorder[i]] = i;
        }

        return solve(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, hashM);
    }
};
