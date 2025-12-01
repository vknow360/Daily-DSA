class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{1,1}, {0,1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        auto isSafe = [&](int x, int y) {
            if(x >= 0 && x < n && y >= 0 && y < n) return true;
            return false;
        };

        vector<vector<int>> dist(n,vector<int>(n, INT_MAX));
        queue<P> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            int d = pq.front().first;
            auto p = pq.front().second;

            int x = p.first;
            int y = p.second;
            pq.pop();

            for(auto dir : directions){
                int X = x + dir[0];
                int Y = y + dir[1];


                if(isSafe(X, Y) && grid[X][Y] == 0 && d + 1 < dist[X][Y]) {
                    pq.push({d+1, {X, Y}});
                    dist[X][Y] = d+1;
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1] + 1;
    }
};