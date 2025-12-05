//Position this line where user code will be pasted.
class Solution {
  public:
    void DFS(vector<vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(!visited[v]) DFS(adj, v, visited, st);
        }
        st.push(u);
    }
    void DFS2(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(!visited[v]) DFS2(adj, v, visited);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<bool> visited(V, false);
        
        // find topo sort order
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) DFS(adj, i, visited, st);
        }
        
        // reverse connections
        vector<vector<int>> newAdj(V);
        for(int i = 0; i < V; i++) {
            for(int& u : adj[i]) {
                newAdj[u].push_back(i);
            }
        }
        
        int ans = 0;
        
        // count SCC
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            
            if(!visited[u]) {
                ans++;
                DFS2(newAdj, u, visited);
            }
        }
        
        return ans;
        
    }
};
