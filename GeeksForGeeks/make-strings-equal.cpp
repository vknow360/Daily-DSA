class Solution {
  public:
    
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        const int INF = INT_MAX;
        int ans = 0;
        
        int V = transform.size();
        vector<vector<int>> dp(26, vector<int>(26, INF));
        for(int i = 0; i < 26; i++) dp[i][i] = 0;
        
        int i = 0;
        for(auto& vec : transform){
            int a = vec[0]-'a', b = vec[1] - 'a';
            dp[a][b] = min(dp[a][b], cost[i]);
            i++;
        }
        
        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dp[i][via] != INF && dp[via][j] != INF){
                        dp[i][j] = min(dp[i][j], dp[i][via]+dp[via][j]);
                    }
                }
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[i]) continue;
            int a = s[i]-'a', b = t[i]-'a';
            // check s[i] to t[i] cost
            int stotCost = dp[a][b];
            // check t[i] to s[i] cost
            int ttosCost = dp[b][a];
            
            int best = INF/2;
            for(int j = 0; j < 26; j++){
                if(dp[a][j] != INF && dp[b][j] != INF)
                    best = min(best, dp[a][j]+dp[b][j]);   
            }
            
            if(stotCost == INF && ttosCost == INF && best == INF/2) return -1;
            else ans += min(best, min(stotCost, ttosCost));
        }
        return ans;
    }
};