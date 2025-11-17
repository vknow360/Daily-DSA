class Solution {
  public:
    vector<int> dp;
    int solve(int i, vector<int>& arr) {
        if(dp[i] != -1) return dp[i];
        
        int mx = 0;
        for(int j = i+1; j < arr.size(); j++){
            if(arr[j] > arr[i]) {
                mx = max(mx, solve(j, arr));
            }
        }
        
        return dp[i] = arr[i] + mx;
    }
    int maxSumIS(vector<int>& arr) {
        // code here
        dp.resize(arr.size(), -1);
        int mxSum = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++){
            mxSum = max(solve(i, arr), mxSum);
        }
        return mxSum;
    }
};