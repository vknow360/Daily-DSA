class Solution {
  public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        auto isSafe = [&](int x, int y){
          if(x<n && y<m && x>=0 && y>=0) return true;
          return false;
        };
        
        
        vector<vector<pair<int,int>>> adj(n*m);

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0,0}});
        
        while(!pq.empty()) {
            auto& tp = pq.top();
            int currEffort = tp.first;
            
            auto& p = tp.second;
            int x = p.first, y = p.second;
            pq.pop();
            
            if (currEffort > effort[x][y]) continue;
            
            for(auto& dir : directions){
                int X = x+dir[0], Y = y+dir[1];
                if(isSafe(X,Y)) {
                    int diff = abs(mat[x][y] - mat[X][Y]);
                    int newEffort = max(currEffort, diff);
                    
                    if(newEffort < effort[X][Y]) {
                        effort[X][Y] = newEffort;
                        pq.push({newEffort, {X, Y}});
                    }
                }
            }
        }
        return effort[n-1][m-1];   
    }
};
