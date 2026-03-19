/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    struct prop {
        bool isBST;
        int size;
        int mn;
        int mx;
    };
    typedef struct prop P;
    P solve(Node *root) {
        if(!root) return {true, 0, INT_MAX, INT_MIN};
        
        P left = solve(root->left);
        P right = solve(root->right);
        int val = root->data;
        if(left.isBST && right.isBST && val > left.mx && val < right.mn) {
            return {
                true, 
                1 + left.size + right.size, 
                min(val, left.mn), 
                max(val, right.mx)
            };
        }
        return {
            false,
            max(left.size, right.size),
            INT_MAX,
            INT_MIN
        };
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        return solve(root).size;
    }
};
