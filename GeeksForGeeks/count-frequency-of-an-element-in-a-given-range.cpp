class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            int e = arr[i];
            mp[e].push_back(i);
        }
        
        vector<int> ans;
        for(auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];
            
            
            int count = 0;
            auto it = mp.find(x);
            if(it != mp.end()) {
                auto& vec = it->second;
                int up = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
                int lo = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
                count = up - lo;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
