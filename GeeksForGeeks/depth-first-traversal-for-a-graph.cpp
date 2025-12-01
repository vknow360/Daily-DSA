class Solution {
  public:
    void helper(vector<vector<int>>& adj, int u, vector<bool> &visited, vector<int> &res){
        if(visited[u]) return;
        
        visited[u] = true;
        res.push_back(u);
        for(int v : adj[u]){
            if(!visited[v]) {
                helper(adj, v, visited, res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> result;
        vector<bool> visited(adj.size(), false);
        helper(adj, 0, visited, result);
        return result;
    }
};