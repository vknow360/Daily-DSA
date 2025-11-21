// User function Template for C++
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int Find(int u){
        if(parent[u] == u) return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v){
        int u_parent = Find(u);
        int v_parent = Find(v);
        
        if(u_parent == v_parent) return;
        
        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }else if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }else {
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        parent.resize(V);
        rank.resize(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
        
        auto comp = [&](auto& a, auto& b){
            return a[2] < b[2];
        };
        sort(edges.begin(), edges.end(), comp);
        
        int cost = 0;
        
        for(auto& vec : edges) {
            int u = vec[0], v = vec[1], wt = vec[2];
            if(Find(u) != Find(v)) {
                cost += wt;
                Union(u, v);
            }
        }
        return cost;
    }
};