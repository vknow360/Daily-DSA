/*
class Node {
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
    vector<int> bfs(Node* root){
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()){
            vector<int> level;
            int len = q.size();
            for(int i = 0; i < len; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(lvl % 2 == 0){
                reverse(level.begin(), level.end());
            }
            for(int i : level) ans.push_back(i);
            lvl++;
        }
        return ans;
    }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        return bfs(root);
    }
};