class Solution {
  public:
    int n, m;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    bool isSafe(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void DFS(
            vector<vector<int>>& grid, 
            vector<vector<bool>>& vis, 
            int x, int y
        ) {
        if(vis[x][y]) return;
        vis[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            
            if(!isSafe(X, Y) || (grid[X][Y] == 0) || vis[X][Y]) {
                continue;
            }
            DFS(grid, vis, X, Y);
        }
        
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int row = 0; row < n; row++) {
            if(grid[row][0] == 1) {
                DFS(grid, vis, row, 0);
            }
            if(grid[row][m-1] == 1) {
                DFS(grid, vis, row, m-1);
            }
        }
        for(int col = 0; col < m; col++) {
            if(grid[0][col] == 1) {
                DFS(grid, vis, 0, col);
            }
            if(grid[n-1][col] == 1) {
                DFS(grid, vis, n-1, col);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
