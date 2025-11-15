class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x, int y) {
            if(x >= 0 && x < m && y >= 0 && y < n) return true;
            return false;
        };

        vector<vector<int>> dist(m,vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            auto p = pq.top().second;

            int x = p.first;
            int y = p.second;

            pq.pop();

            for(auto dir : directions){
                int X = x + dir[0];
                int Y = y + dir[1];

                if(isSafe(X,Y)) {
                    int absDiff = abs(heights[x][y] - heights[X][Y]);
                    int mxDiff = max(d, absDiff);

                    if(dist[X][Y] > mxDiff) {
                        dist[X][Y] = mxDiff;
                        pq.push({mxDiff, {X,Y}});
                    }
                }
            }
        }

        return dist[m-1][n-1];

    }
};