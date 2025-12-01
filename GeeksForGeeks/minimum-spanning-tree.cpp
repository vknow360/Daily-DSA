class Solution {
  public:
    typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<P>> adj(V);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMst(V, false);
        
        int sum = 0;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto& p = pq.top();
            int w = p.first;
            int node = p.second;
            pq.pop();
            
            if(inMst[node]) continue;
            
            inMst[node] = true;
            sum += w;
            
            for(auto& pr : adj[node]){
                int wt = pr.first;
                int v = pr.second;
                
                if(!inMst[v]){
                    pq.push({wt, v});
                    
                }
            }
        }
        
        return sum;
        
    }
};