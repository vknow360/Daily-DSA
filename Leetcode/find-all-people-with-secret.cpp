class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        set<int> times;
        for (auto& vec : meetings) {
            times.insert(vec[2]);
        }

        unordered_map<int, vector<vector<int>>> tmt;

        for (auto& vec : meetings) {
            tmt[vec[2]].push_back({vec[0], vec[1]});
        }

        vector<bool> know(n, false);
        know[0] = know[firstPerson] = true;

        for (auto it = times.begin(); it != times.end(); it = next(it)) {
            int i = *(it);
            if (tmt[i].empty())
                continue;
            // build sub-graph
            unordered_map<int, vector<int>> adj;
            for (auto& vec : tmt[i]) {
                adj[vec[0]].push_back(vec[1]);
                adj[vec[1]].push_back(vec[0]);
            }
            // check if any person in this graph knows secret
            queue<int> q;
            for (auto& [k, v] : adj) {
                if (know[k]) q.push(k);
            }

            while (!q.empty()) {
                auto tp = q.front();
                q.pop();

                know[tp] = true;
                for (int v : adj[tp]) {
                    if (!know[v])
                        q.push(v);
                }
            }
        }

        // return all indexes where true is marked in know array
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (know[i])
                ans.push_back(i);
        }
        return ans;
    }
};
