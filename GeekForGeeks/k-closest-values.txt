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
    void inorder(Node* root, vector<int> &arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        
        int left = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        vector<int> ans;
        
        int i = left-1;
        int j = left;
        while(ans.size() < k){
            int d1, d2;
            if(i >= 0){
                d1 = abs(arr[i] - target);
            }else break;
            if(j <= n-1){
                d2 = abs(arr[j] - target);
            }else break;
            
            if(d1 <= d2){
                ans.push_back(arr[i]);
                i--;
            }else{
                ans.push_back(arr[j]);
                j++;
            }
        }
        while(ans.size() < k && i >= 0){
            ans.push_back(arr[i]);
            i--;
        }
        while(ans.size() < k && j <= n-1){
            ans.push_back(arr[j]);
            j++;
        }
        
        return ans;
    }
};