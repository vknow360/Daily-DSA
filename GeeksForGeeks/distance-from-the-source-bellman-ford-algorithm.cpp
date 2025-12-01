// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        
        
        dist[src] = 0;
        
        for(int i = 1; i <= V-1; i++){
            for(auto& vec : edges){
                int u = vec[0], v = vec[1], w = vec[2];
                
                if(dist[u] == 1e8) continue;
                
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        bool change = false;
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], w = vec[2];
                
            if(dist[u] == 1e8) continue;
                
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                change = true;
                break;
            }
        }
        
        if(change){
            return {-1};
        }
        return dist;
    }
};
