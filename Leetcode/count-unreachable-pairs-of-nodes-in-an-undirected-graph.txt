class Solution {
public:
    long long DFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;
        long long size = 1;
        for(int& v : adj[u]){
            if(!visited[v]) size += DFS(adj, v, visited);
        }

        return size;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        long long total = (1LL*n*(n-1))/2;
        long long reachable = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                long long count = DFS(adj, i, visited);
                reachable += (1LL * count * (count-1))/2;
            }
        }
        return total - reachable;
    }
};