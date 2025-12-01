/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    bool inorder(Node* root, int k, int &count, int &result) {
        if (!root) return false;

        if (inorder(root->left, k, count, result)) return true;

        count++;
        if (count == k) {
            result = root->data;
            return true;
        }

        return inorder(root->right, k, count, result);
    }

    int kthSmallest(Node* root, int k) {
        // code here
        int count = 0, result = -1;
        inorder(root, k, count, result);
        return result;
    }
};
