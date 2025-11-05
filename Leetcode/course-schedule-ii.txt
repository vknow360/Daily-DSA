class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(const auto& vec : prerequisites){
            int u = vec[1], v = vec[0];
            adj[u].push_back(v);
        }

        vector<int> ans;

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }

        int count = 0;
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            count++;
            ans.push_back(fr);

            for(int& v : adj[fr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(count == numCourses) return ans;
        return {};
    }
};