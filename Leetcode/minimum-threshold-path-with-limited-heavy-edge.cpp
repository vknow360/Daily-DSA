class Solution {
public:
    bool dfs(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int src, int des, int thres, int k, int h) {
        if(src == des) return true;
        for(auto& [v, w] : adj[src]) {
            int nH = h + (w > thres ? 1 : 0);
            if(nH <= k && nH < dist[v]) {
                dist[v] = nH;
                if(dfs(adj, dist, v, des, thres, k, nH)) return true;
            }
        }
        return false;
    }
    bool isPath(vector<vector<pair<int, int>>>& adj, int src, int des, int thres, int k) {
        int n = adj.size();
        vector<int> dist;
        dist.assign(n, INT_MAX);

        dist[src] = 0;
        return dfs(adj, dist, src, des, thres, k, 0);
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source == target) return 0;
        vector<vector<pair<int, int>>> adj;
        adj.assign(n, {});
        
        unordered_set<int> weights;
        for(auto& vec : edges) {
            int u = vec[0], v = vec[1], w = vec[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            weights.insert(w);
        }

        vector<int> wts(weights.begin(), weights.end());
        wts.push_back(0);
        sort(wts.begin(), wts.end());

        int lo = 0, hi = wts.size()-1, res = -1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(isPath(adj, source, target, wts[mid], k)) {
                res = wts[mid];
                hi = mid-1;
            }else lo = mid+1;
        }
        return res;
    }
};
