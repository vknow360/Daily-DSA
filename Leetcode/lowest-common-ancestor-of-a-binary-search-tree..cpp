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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;

        int val = root->val;    
        int pVal = p->val;
        int qVal = q->val;

        if (pVal < val && qVal < val)
            return lowestCommonAncestor(root->left, p, q);
        if (pVal > val && qVal > val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};