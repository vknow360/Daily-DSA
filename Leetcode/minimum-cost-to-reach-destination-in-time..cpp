class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    const int INF = INT_MAX;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int V = passingFees.size();
        vector<vector<pair<int,int>>> adj(V);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], t = vec[2];
            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }
        vector<vector<int>> dp(V, vector<int>(maxTime+1, INF));
        dp[0][0] = passingFees[0];

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({passingFees[0], {0, 0}});

        while(!pq.empty()) {
            auto& tp = pq.top();
            int fee = tp.first;
            int ct = tp.second.first;
            int tm = tp.second.second;

            pq.pop();

            if(fee > dp[ct][tm]) continue;

            for(auto& [time, city] : adj[ct]) {
                int newTime = time+tm;
                if(newTime > maxTime) continue;

                int newCost = fee+passingFees[city];
                if(newCost < dp[city][newTime]) {
                    dp[city][newTime] = newCost;
                    pq.push({newCost, {city, newTime}});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i <= maxTime; i++){
            ans = min(dp[V-1][i], ans);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};