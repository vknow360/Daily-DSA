class Solution {
  public:
    int validGroups(string &s) {
        // code here
        int n = s.size();
        int prevMx = 0;
        for(char c : s) prevMx += c-'0';
        
        vector<vector<int>> dp;
        dp.assign(n+1, vector<int>(prevMx + 1));
        
        for(int i = 0; i <= prevMx; i++) {
            dp[n][i] = 1;
        }
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev = prevMx; prev >= 0; prev--) {
                int ans = 0;
                int sum = 0;
                for(int i = idx; i < n; i++) {
                    sum += s[i] - '0';
                    if(sum >= prev) {
                        ans += dp[i+1][sum];
                    }
                }
                dp[idx][prev] = ans;
            }
        }
        
        return dp[0][0];
    }
};
