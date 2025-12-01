class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'S') return;
        
        grid[i][j] = 'O';
        dfs(grid, n, m, i+1, j);
        dfs(grid, n, m, i-1, j);
        dfs(grid, n, m, i, j+1);
        dfs(grid, n, m, i, j-1);
        
    }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X') continue;
                
                grid[i][j] = 'S';
            }
        }
        set<pair<int,int>> s;
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 'S') s.insert({0,i});
            if(grid[n-1][i] == 'S') s.insert({n-1,i});
        }
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 'S') s.insert({i,0});
            if(grid[i][m-1] == 'S') s.insert({i,m-1});
        }
        
        for(const auto [i, j] : s){
            dfs(grid, n, m, i, j);   
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 'S') continue;
                
                grid[i][j] = 'X';
            }
        }
    }
};