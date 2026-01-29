class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        vector<vector<long long>> dp(26, vector<long long>(26, INT_MAX));
        for(int i = 0; i < 26; i++) {
            dp[i][i] = 0;
        }
        for(int i = 0; i < n; i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            dp[u][v] = min(dp[u][v], 1LL*cost[i]);
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue;
                    if(dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }

        long long ans = 0LL;
        for(int i = 0; i < source.size(); i++) {
            char u = source[i];
            char v = target[i];

            long long cst = dp[u-'a'][v-'a'];
            if(cst == INT_MAX) return -1;
            ans += cst;
        }

        return ans;
    }
};
