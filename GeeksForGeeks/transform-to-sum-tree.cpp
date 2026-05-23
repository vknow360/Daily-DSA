class Solution {
  public:
    int solve(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            int val = root->data;
            root->data = 0;
            return val;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        int val = root->data;
        root->data = left+right;
        return left+right+val;
    }
    void toSumTree(Node *root) {
        // code here
        solve(root);
    }
};
