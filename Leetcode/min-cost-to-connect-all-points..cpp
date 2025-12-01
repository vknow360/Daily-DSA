class Solution {
public:
    typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        vector<bool> inMst(n, false);

        int cost = 0;

        while(!pq.empty()){
            auto& p = pq.top();
            int i = p.second;
            int d = p.first;

            pq.pop();

            if(inMst[i]) continue;

            inMst[i] = true;
            cost += d;

            for(auto& j : adj[i]) {
                int node = j.second;
                int dt = j.first;

                if(!inMst[node]) {
                    pq.push({dt, node});
                }
            }
        }
        return cost;
    }
};