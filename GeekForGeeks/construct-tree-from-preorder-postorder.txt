/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    unordered_map<int,int> postIndex;
    Node* build(vector<int> &pre, int prelo, int prehi, vector<int> &post, int postlo, int posthi){
        if(prelo > prehi) return NULL;
        Node* root = new Node(pre[prelo]);
        if(prelo==prehi) return root;
        int i = postIndex[pre[prelo+1]];
        
        int leftCount = i - postlo + 1;
        int rightCount = posthi - i;
        root->left = build(pre, prelo+1, prelo+leftCount, post, postlo, i);
        root->right = build(pre, prelo+leftCount+1, prehi, post, i+1, posthi-1);
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int n = pre.size();
        for(int i = 0; i < n; i++){
            postIndex[post[i]] = i;
        }
        return build(pre, 0, n-1, post, 0, n-1);
        
    }
};