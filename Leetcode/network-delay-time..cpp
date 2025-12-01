class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> adj(n+1);
        for(auto& vec : times){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v,w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = INT_MIN;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            for(auto& p : adj[node]){
                int v = p.first, wt = p.second;

                if(d+wt < dist[v]){
                    dist[v] = d+wt;
                    pq.push({d+wt, v});
                }
            }
        }

        for(int i : dist){
            if(i == INT_MAX) return {-1};
        }

        return *max_element(dist.begin(), dist.end());
    }
};