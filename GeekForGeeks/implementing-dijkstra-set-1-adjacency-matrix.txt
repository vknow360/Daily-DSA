// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], wt = vec[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result(V, INT_MAX);
        
        result[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto& p : adj[node]){
                int adjNode = p.first;
                int wt = p.second;
                
                if(d + wt < result[adjNode]){
                    result[adjNode] = d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        
        return result;
    }
};