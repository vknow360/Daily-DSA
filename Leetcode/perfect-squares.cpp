class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;

        for(int i = 1; i*i <= n; i++) {
            sq.push_back(i*i);
        }

        vector<int> dp;
        dp.assign(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int num : sq) {
                if(i < num) break;
                dp[i] = min(dp[i], 1 + dp[i - num]);
            }
        }

        return dp[n];
    }
};
