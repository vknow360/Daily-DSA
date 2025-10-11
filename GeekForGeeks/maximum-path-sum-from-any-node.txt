/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int levels(Node* root, int& globalMax) {
        if (root == nullptr)
            return 0;
        int left = max(0, levels(root->left, globalMax));
        int right = max(0, levels(root->right, globalMax));
        globalMax = max(globalMax, root->data + max(0, left) +
                                       max(0, right));
        return root->data+ max(left, right);
    }
    int findMaxSum(Node *root) {
        // code here
        if (!root)
            return 0;
        int mx = INT_MIN;
        levels(root, mx);
        return mx;
    }
};