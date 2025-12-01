class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool> &visited, int parent){

        visited[u] = true;
        
        for(int v : adj[u]){
            if(v == parent) continue;
            
            if(visited[v] || isCycleDFS(adj, v, visited, u)) return true;
        }
        
        return false;
    }
    
    bool isCycleBFS(vector<vector<int>>& adj, int i, vector<bool>& visited){
        
        
        queue<pair<int,int>> q;
        q.push({i, -1});
        visited[i] = true;
        
        while(!q.empty()){
            auto p = q.front();
            int u = p.first, parent = p.second;
            q.pop();
            
            for(int v : adj[u]){
                if(v == parent) continue;
                
                if(visited[v]) return true;
                
                visited[v] = true;
                q.push({v, u});
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adj(V, vector<int>());
        for(vector<int> vec : edges){
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(adj.size(), false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleBFS(adj, i, visited)) return true;
        }
        
        return false;
    }
};