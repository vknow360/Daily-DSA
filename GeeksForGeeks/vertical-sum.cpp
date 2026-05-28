class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        if(!root) return {};
        unordered_map<int, int> mp;
        int mx = INT_MIN, mn = INT_MAX;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto tp = q.front(); q.pop();
            Node* nd = tp.first;
            int dis = tp.second;
            
            mp[dis] += nd->data;
            
            mx = max(mx, dis);
            mn = min(mn, dis);
            
            if(nd->left) {
                q.push({nd->left, dis-1});
            }
            if(nd->right) {
                q.push({nd->right, dis+1});
            }
        }
        
        vector<int> ans;
        for(int i = mn; i <= mx; i++) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
