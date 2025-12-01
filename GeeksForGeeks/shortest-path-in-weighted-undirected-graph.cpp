class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& vec : edges){
            int u = vec[0], v = vec[1], wt = vec[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result(n+1, INT_MAX);
        
        vector<int> parent(n+1);
        
        for(int i = 1; i <= n; i++) parent[i] = i;
        
        result[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto& p : adj[node]){
                int adjNode = p.first;
                int wt = p.second;
                
                if(d + wt < result[adjNode]){
                    result[adjNode] = d+wt;
                    parent[adjNode] = node;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        
        if(result[n] == INT_MAX) return {-1};
        
        vector<int> ans;
        int tmp = n;
        while(parent[tmp] != tmp){
            ans.push_back(tmp);
            tmp = parent[tmp];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(), ans.end());
        ans.insert(ans.begin(), result[n]);
        return ans;
        
    }
};