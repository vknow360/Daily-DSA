class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int m, int n, int curr, int k, int i, int j) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1){
            return (curr+grid[i][j])%k == 0;
        }

        if(dp[i][j][curr] != -1) return dp[i][j][curr];

        int r = (curr+(grid[i][j]))%k;
        int down = solve(grid, m, n, r, k, i+1, j);
        int right = solve(grid, m, n, r, k, i, j+1);
        return dp[i][j][curr] = (down+right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid, m, n, 0, k, 0, 0);
    }
};