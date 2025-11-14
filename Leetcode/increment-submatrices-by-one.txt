class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0));

        for(auto& v : queries){
            int r1 = v[0], c1 = v[1], r2 = v[2], c2 = v[3];
            grid[r1][c1] += 1;
            if(c2+1 < n) {
                grid[r1][c2+1] -= 1;
            }
            if(r2+1 < n){
                grid[r2+1][c1] -= 1;
            }
            if(r2+1 < n && c2+1 < n){
                grid[r2+1][c2+1] += 1;
            }
        }

        for(int i = 1; i < n; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int j = 1; j < n; j++){
            grid[j][0] += grid[j-1][0];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        return grid;
    }
};