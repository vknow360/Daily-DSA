class Solution {
  public:
    void DFS(vector<vector<int>>& adj, vector<int>& curr, int node, vector<bool>& vis){
        vis[node] = true;
        curr.push_back(node);
        
        for(int v : adj[node]){
            if(!vis[v]) {
                DFS(adj, curr, v, vis);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < V; i++){
            vector<int> curr;
            if(!vis[i]) {
                DFS(adj, curr, i, vis);
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};
