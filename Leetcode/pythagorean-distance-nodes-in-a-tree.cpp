class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& adj, int src) {
        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        vector<int> dx = bfs(n, adj, x);
        vector<int> dy = bfs(n, adj, y);
        vector<int> dz = bfs(n, adj, z);

        for(int i = 0; i < n; i++) {
            if(dx[i] == -1 || dy[i] == -1 || dz[i] == -1) continue;
            long long a = dx[i];
            long long b = dy[i];
            long long c = dz[i];
            long long sum = a+b+c;
            long long mn = min({a,b,c});
            long long mx = max({a,b,c});
            b = sum - mn - mx;
            if(mn*mn + b*b == mx*mx) ans++;
        }

        return ans;
    }
};
