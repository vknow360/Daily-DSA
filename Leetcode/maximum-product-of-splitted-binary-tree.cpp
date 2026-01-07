class Solution {
public:
    long long ans = 0;
    long long total = 0;
    static const int MOD = 1000000007;

    long long totalSum(TreeNode* root) {
        if(!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if(!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long sub = left + right + root->val;

        ans = max(ans, sub * (total - sub));

        return sub;
    }

    int maxProduct(TreeNode* root) {
        total = totalSum(root);
        dfs(root);
        return ans % MOD;
    }
};
