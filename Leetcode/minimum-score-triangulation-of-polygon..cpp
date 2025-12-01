class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        const long long INF = (1LL << 60);
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for (int k = i + 1; k < j; k++) {
                    long long cost = dp[i][k] + dp[k][j] +
                                     1LL * values[i] * values[k] * values[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return (int)dp[0][n-1];
    }
};