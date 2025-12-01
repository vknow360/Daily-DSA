class Solution {
  public:
    int find(int x, vector<int>& parent){
        if (parent[x] != x)
                parent[x] = find(parent[x], parent);
        return parent[x];
    }
    
    void Union(vector<int>& parent, vector<int>& rank, int u, int v){
        int u_parent = find(u, parent);
            int v_parent = find(v, parent);
            
            if(u_parent == v_parent) return;
            
            if(rank[u_parent] > rank[v_parent]){
                parent[v_parent] = u_parent;
            }else if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }else {
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> parent(V);
        vector<int> rank(V, 1);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        
        for(int u = 0; u < V; u++){
            for(int& v : adj[u]){
                if(u < v) {
                    int u_parent = find(u, parent);
                    int v_parent = find(v, parent);
                    
                    if(u_parent == v_parent) return true;
                    
                    
                    Union(parent, rank, u, v);
                }
            }
        }
        
        return false;
    }
};