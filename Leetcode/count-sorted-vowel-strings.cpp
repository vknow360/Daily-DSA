class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<long long>> dp;
        dp.assign(n+1, vector<long long>(5, 0));
        for(int st = 0; st < 5; st++) {
            dp[1][st] = 5-st;
        }
        for(int i = 2; i <= n; i++) {
            for(int st = 4; st >= 0; st--) {
                if(st == 4) dp[i][st] = dp[i-1][st];
                else dp[i][st] = dp[i][st+1] + dp[i-1][st];
            }
        }
        return dp[n][0];
    }
};
