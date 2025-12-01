class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1, vector<int>());
        for (const auto& vec : connections) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c+1, false);

        vector<set<int>> active;

        unordered_map<int, int> mp;

        for (int i = 1; i <= c; i++) {
            if (visited[i])
                continue;
            int idx = active.size();
            set<int> grid;
            stack<int> st;
            st.push(i);
            while (!st.empty()) {
                int u = st.top();
                st.pop();
                grid.insert(u);
                mp[u] = idx;
                visited[u] = true;

                for (int& v : adj[u]) {
                    if (!visited[v])
                        st.push(v);
                }
            }

            active.push_back(grid);
        }

        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int station = q[1];
                const auto& activeStations = active[mp[q[1]]];
                if (activeStations.count(station)) {
                    ans.push_back(station);
                } else {
                    if(!activeStations.empty()){
                        ans.push_back(*activeStations.begin());
                    }else {
                        ans.push_back(-1);
                    }
                }
            } else {
                active[mp[q[1]]].erase(q[1]);
            }
        }

        return ans;
    }
};