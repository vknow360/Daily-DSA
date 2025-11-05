class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1, vector<int>());

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    int u = i+1, v = j+1;
                    adj[u].push_back(v);
                    adj[v].push_back(v);
                }
            }
        }

        int count = 0;

        vector<bool> visited(n+1, false);

        for(int i = 1; i <= n; i++){
            if(!visited[i]) {
                DFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};