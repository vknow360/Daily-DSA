/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void reverseInorder(Node *root, int &sum){
        if(!root) return;
        reverseInorder(root->right, sum);
        int val = sum;
        sum = root->data + sum;
        root->data = val;
        reverseInorder(root->left, sum);
    }
    void transformTree(Node *root) {
        // code here
        int sum = 0;
        reverseInorder(root, sum);
    }
};