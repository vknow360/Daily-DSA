class Solution {
  public:
    void flatten(Node *root, string& s) {
        if(!root) {
            s += "|";
            return;
        }
        
        s += "#" + to_string(root->data) + "#";
        flatten(root->left, s);
        flatten(root->right, s);
    }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        string s = "", t = "";
        flatten(root1, s);
        flatten(root2, t);
        
        return s.find(t) != string::npos;
    }
};
