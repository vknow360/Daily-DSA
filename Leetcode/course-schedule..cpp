class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& adj, vector<int>& indegree){
        queue<int> q;

        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return count != V;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        vector<vector<int>> adj(numCourses, vector<int>());
        for(vector<int> vec : prerequisites){
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        return !isCycle(numCourses, adj, indegree);
    }
};