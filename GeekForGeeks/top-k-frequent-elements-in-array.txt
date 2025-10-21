class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(int i : arr){
            mp[i]++;
        }
        
        vector<pair<int,int>> imp;
        for(auto& [num, freq] : mp){
            imp.push_back({freq, num});
        }
        
        sort(imp.begin(),imp.end(), greater<>());
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = imp[i].second;
        }
        
        return ans;
    }
};