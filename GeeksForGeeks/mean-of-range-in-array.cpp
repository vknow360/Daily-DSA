class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> pref = arr;
        for(int i = 1; i < n; i++) pref[i] += pref[i-1];
        
        vector<int> res;
        for(auto& vec : queries) {
            int l = vec[0], r = vec[1];
            int len = r-l+1;
            
            int sum = pref[r] - (l > 0 ? pref[l-1] : 0);
            res.push_back(sum/len);
        }
        return res;
    }
};
