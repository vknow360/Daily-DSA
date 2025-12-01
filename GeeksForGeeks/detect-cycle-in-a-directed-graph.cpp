class Solution {
  public:
    bool isCycleDFS(vector<vector<int>> adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(int v : adj[u]){
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) return true;
            else if(inRecursion[v] == true) return true;
        }
        inRecursion[u] = false;
        return false;
    }
    
    bool isCycleBFS(int V, vector<vector<int>>& adj){
        //Kahn's Algorithm
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            count++;
            for(int v : adj[fr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return count != V;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V, vector<int>());
        for(vector<int> vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
        }
        
        // vector<bool> visited(V, false);
        // vector<bool> inRecursion(V, false);
        
        // for(int i = 0; i < V; i++){
        //     if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)) return true;
        // }
        
        //return false;
        
        return isCycleBFS(V, adj);
    }
};