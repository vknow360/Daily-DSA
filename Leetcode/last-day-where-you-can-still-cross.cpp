class Solution {
public:
    bool canReach(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0)); // build adj matrix
        for (int i = 0; i < day; i++) {
            int r = cells[i][0], c = cells[i][1];
            grid[r - 1][c - 1] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int c = 0; c < col; c++) {
            if (grid[row - 1][c] == 0) {
                q.push({row - 1, c});
                vis[row - 1][c] = true;
            }
        }

        // check reachability
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == 0) return true; // reached top

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        int lo = 1;
        int hi = n;
        int ans = 0;
        while (lo <= hi) {
            int day = lo + (hi - lo) / 2;
            if (canReach(row, col, cells, day)) {
                ans = day;
                lo = day + 1; // try for a higher day
            } else
                hi = day - 1;
        }

        return ans;
    }
};
