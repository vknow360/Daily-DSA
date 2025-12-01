class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int Find(int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
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
    bool IsSameGroup(int x, int y){
        return Find(x) == Find(y);
    }
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        if(edges.size() < V-1) return -1;

        parent.resize(V);
        rank.resize(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
        
        int count = 0;
        
        for(auto& vec : edges){
            int u = vec[0], v = vec[1];
            if(IsSameGroup(u, v)) {
                count++;
            }else Union(u, v);
        }
        
        int components = 0;
        for(int i = 0; i < V; i++) {
            if(Find(i) == i) components++;
        }
        
        if(count >= components-1) return components-1;
        else return -1;
    }
};
