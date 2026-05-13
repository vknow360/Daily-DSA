class Solution {
  public:
    bool DFS(vector<vector<int>>& adj, unordered_set<int>& st, int u) {
        if(st.size() == adj.size()) return true;
        
        for(auto& v : adj[u]) {
            if(st.count(v)) continue;
            st.insert(v);
            if(DFS(adj, st, v)) return true;
        }
        return false;
    }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
        }
        
        int candidate = -1;
        unordered_set<int> st;
        for(int i = 0; i < V; i++) {
            if(st.count(i)) continue;
            st.insert(i);
            DFS(adj, st, i);
            candidate = i;
        }
        st = {};
        st.insert(candidate);
        if(DFS(adj, st, candidate)) return candidate;
        return -1;
    }
};
