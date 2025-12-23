class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        ans.reserve(queries.size());
        sort(arr.begin(), arr.end());
        
        for(auto& q : queries) {
            int left = lower_bound(arr.begin(), arr.end(), q[0]) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), q[1]) - arr.begin();
            ans.push_back(right - left);
        }
        return ans;
    }
};
