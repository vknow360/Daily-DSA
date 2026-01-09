class Solution {
public:
    int mxD = 0;
    void depth(TreeNode* root, int d) {
        if(!root) return;

        mxD = max(mxD, d);
        depth(root->left, d+1);
        depth(root->right, d+1);
    }
    TreeNode* helper(TreeNode* root, int d) {
        if(!root) return nullptr;

        if(d<mxD) {
            TreeNode* left = helper(root->left, d+1);
            TreeNode* right = helper(root->right, d+1);

            if(left && right) return root;
            if(left) return left;
            return right;
        }

        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;

        depth(root, 0);
        return helper(root, 0);
    }
};
