class Solution {
  public:
    typedef pair<int, int> P;
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        int src = 0, dst = V-1;
        
        vector<vector<P>> adj(V);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        vector<int> dist(V, INT_MAX), count(V, 0);
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0] = 0;
        count[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int tm = tp.first;
            int u = tp.second;
            
            if(tm > dist[u]) continue;
            
            for(auto& ed : adj[u]) {
                int t = ed.first;
                int v = ed.second;
                
                if(dist[u] + t <= dist[v]) {
                    if(dist[u] + t == dist[v]) {
                        count[v] += count[u];
                    }else {
                        count[v] = count[u];
                        dist[v] = dist[u]+t;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return count.back();
    }
};
