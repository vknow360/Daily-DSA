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
    
    void inorder(TreeNode* root, vector<long long> &arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<long long> arr;
        inorder(root, arr);
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] <= arr[i-1]) return false;
        }
        return true;
    }
};