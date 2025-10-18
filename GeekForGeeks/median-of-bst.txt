/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> &arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    int findMedian(Node* root) {
        // Code here
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        return n%2==0 ? arr[(n/2)-1] : arr[((n+1)/2)-1];
    }
};