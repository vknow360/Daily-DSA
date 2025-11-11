class Solution {
public:
    int dp[101][101][601];
    int solve(vector<pair<int,int>>& count, int m, int n, int i){
        if(i >= count.size()) return 0;


        if(dp[m][n][i] != -1) return dp[m][n][i];

        // skip
        int op1 = solve(count, m, n, i+1);

        // take
        int op2 = 0;
        auto& p = count[i];
        if(p.first <= m && p.second <= n){
            op2 = 1 + solve(count, m-p.first, n-p.second, i+1);
        }

        return dp[m][n][i] = max(op1, op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //sort(strs.begin(), strs.end());
        vector<pair<int,int>> count;
        for(string s : strs){
            int cnt = 0;
            for(char c : s){
                if(c=='0') cnt++;
            }
            count.push_back({cnt, s.size() - cnt});
        }

        memset(dp, -1, sizeof(dp));

        return solve(count, m, n, 0);
    }
};
