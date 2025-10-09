/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void postorder(vector<int> &ans, Node* root){
        if(!root) return;
        postorder(ans, root->left);
        postorder(ans, root->right);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        postorder(ans, root);
        return ans;
    }
};