class Solution {
  public:
    bool DFS(vector<vector<int>>& adj, int u, vector<int>& color, int curr){
        color[u] = curr;
        
        for(int& v : adj[u]){
            if(color[v] == curr) return false;
            
            if(color[v] == -1){
                int colorV = 1 - curr;
                if(!DFS(adj, v, color, colorV)) return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V, vector<int>());
        for(vector<int> vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(!DFS(adj, i, color, 1)) return false;
            }
        }
        
        return true;
    }
};