class Solution {
public:
    // 0-> not discovered, 1->false, 2->true
    vector<vector<int>> memo;
    bool isPossible(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || col < 0 || col >= n) return false;
        if(memo[row][col] != 0) return memo[row][col]==2;
        if(grid[row][col] != 0) {
            memo[row][col] = 1;
            return false;
        }
        if(row == 0) {
            memo[row][col] = 2;
            return true;
        }

        memo[row][col] = 1;

        if((row > 0 && isPossible(grid, row-1, col))
        || (col > 0 && isPossible(grid, row, col-1))
        || (col < n-1 && isPossible(grid, row, col+1))
        || (row < m-1 && isPossible(grid, row+1, col))) {
            memo[row][col] = 2;
            return true;
        }

        return false;
    }
    bool solve(int row, int col, vector<vector<int>>& cells, int day) {
        // build adj matrix
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i = 0; i < day; i++) {
            int r = cells[i][0], c = cells[i][1];
            grid[r-1][c-1] = 1;
        }

        // check feasibility 
        for(int i = 0; i < col; i++) {
            memo.assign(row, vector<int>(col, 0));
            if(isPossible(grid, row-1, i)) return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo <= hi) {
            int day = lo + (hi-lo)/2;
            if(solve(row, col, cells, day)) {
                // try for a higher day
                ans = day;
                lo = day+1;
            }else hi = day-1;
        }

        return ans;
    }
};
