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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
        helper(root, targetSum, 0, path,ans );
        return ans;
    }

    void helper(TreeNode* root, int targetSum, int curr, vector<int>& path, vector<vector<int>>& ans){
        if(!root) return;
        curr += root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(curr == targetSum){
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        helper(root->left, targetSum, curr, path, ans);
        helper(root->right, targetSum, curr, path, ans);
        path.pop_back();
    }
};