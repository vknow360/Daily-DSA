class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(int v : adj[u]){
            if(!visited[v]) DFS(adj, v, visited, st);
        }
        st.push(u);
        
    }
    
    void BFS(int V, vector<vector<int>>& adj, vector<int>& ans){
        //Kahn's Algorithm
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            
            for(int v : adj[fr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V, vector<int>());
        for(vector<int> vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
        }
        
        // vector<bool> visited(V, false);
        // stack<int> st;
        
        // for(int i = 0; i < V; i++){
        //     if(!visited[i]) DFS(adj, i, visited, st);
        // }
        
        // vector<int> topo;
        // while(!st.empty()){
        //     int i = st.top();
        //     st.pop();
            
        //     topo.push_back(i);
        // }
        
        // return topo;
        
        vector<int> ans;
        BFS(V, adj, ans);
        return ans;
        
    }
};