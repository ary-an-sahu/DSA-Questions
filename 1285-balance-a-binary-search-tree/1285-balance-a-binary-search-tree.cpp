class Solution {
public:

    void inorder(TreeNode* &root, vector<int> &arr){
        if(root == NULL) return ;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

    }

    TreeNode* buildTree(vector<int>& arr, int s , int e){

        if(s>e){
            return NULL;
        }

        int mid = (s+e)/2;
        int element = arr[mid];
        TreeNode* root = new TreeNode(element);

        root->left = buildTree(arr,s, mid-1);
        root->right = buildTree(arr, mid+1, e);

        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;

        inorder(root, arr);


        //build balanced BST using  inorder traversal
        return buildTree(arr , 0, arr.size() -1);
    }
};