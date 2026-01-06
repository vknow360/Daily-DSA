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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int ans = 1;
        int lvlSum = root->val;
        int currLevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int currSum = 0;
            for(int i = 0; i < sz; i++) {
                auto tp = q.front();
                q.pop();

                currSum += tp->val;
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }
            if(currSum > lvlSum) {
                ans = currLevel;
                lvlSum = currSum;
            }
            currLevel++;
        }
        return ans;
    }
};
