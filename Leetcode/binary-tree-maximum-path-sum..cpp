/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root, int& globalMax) {
        if (root == nullptr)
            return 0;
        int left = max(0, levels(root->left, globalMax));
        int right = max(0, levels(root->right, globalMax));
        globalMax = max(globalMax, root->val + max(0, left) +
                                       max(0, right));
        return root->val+ max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int mx = INT_MIN;
        levels(root, mx);
        return mx;
    }
};