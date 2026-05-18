class Solution {
  public:
    
    int maxSum(int n) {
        // code here.
        vector<int> dp;
        dp.assign(n+1, 0);
        
        for(int i = 0; i <= n; i++) {
            dp[i] = i;
        }
        
        for(int i = 5; i <= n; i++) {
            dp[i] = max(dp[i], dp[i/2] + dp[i/3] + dp[i/4]);
        }
        return dp[n];
    }
};
