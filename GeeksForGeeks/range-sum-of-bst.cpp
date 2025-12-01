/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root, int l, int r, int &sum){
        if(!root) return;
        int val = root->data;
        if(val >= l && val <= r){
            sum += root->data;
        }
        if(l <= val){
            helper(root->left, l, r, sum);
        }
        if(r >= val){
            helper(root->right, l, r, sum);
        }
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        int sum = 0;
        helper(root, l, r, sum);
        return sum;
    }
};
