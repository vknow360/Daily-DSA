class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < n; i++) {
            auto& vec = arr[i];
            int currSt = vec[0], currEn = vec[1];
            if(currSt <= ans.back()[1]) {
                // change end
                ans.back()[1] = max(ans.back()[1], currEn);
            }else {
                // no overlap
                ans.push_back(vec);
            }
        }
        return ans;
    }
};
