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
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(!DFS(graph, i, color, 1)) return false;
            }
        }
        
        return true;
    }
};