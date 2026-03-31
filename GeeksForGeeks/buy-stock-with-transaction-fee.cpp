class Solution {
  public:
    // int solve(vector<int>& arr, int k, bool hold, int curr) {
    //     if(curr == arr.size()) return 0;
        
    //     if(dp[curr][hold] != -1) return dp[curr][hold];
        
    //     int ans = 0;
    //     if(!hold) {
    //         int take = solve(arr, k, !hold, curr+1) - arr[curr];
    //         ans = max(ans, take);
    //     }else {
    //         // already have a stock, must sell now or later
    //         int sell = arr[curr] - k + solve(arr, k, !hold, curr+1);
    //         ans = max(ans, sell);
    //     }
    //     int skip = solve(arr, k, hold, curr+1);
    //     ans = max(ans, skip);
        
    //     return dp[curr][hold] = ans;
    // }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp;
        dp.assign(n+1, vector<int>(2, -1));
        
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            dp[i][0] = max(
                -arr[i] + dp[i+1][1], // buy
                dp[i+1][0]            // skip
            );
            dp[i][1] = max(
                arr[i] - k + dp[i+1][0], // sell
                dp[i+1][1]               // skip
            );
        }
        
        return dp[0][0];
    }
};
