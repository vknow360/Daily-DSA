class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 2;

        vector<vector<int>> adj(n);
        for (auto& vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                for (int v : adj[p.first]) {
                    if (v == p.second)
                        continue;
                    q.push({v, p.first});
                }
            }
            depth++;
        }

        long long ans = power(2, depth - 2);
        // for(int i = 0; i < depth-1; i++) {
        //     ans *= 2;
        //     ans %= MOD;
        // }
        return ans % MOD;
    }
};
