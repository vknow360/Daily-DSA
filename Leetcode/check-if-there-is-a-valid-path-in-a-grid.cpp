class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<vector<int>>> dir = {
        {},
        {{0, -1}, {0, 1}},  // 1
        {{-1, 0}, {1, 0}},  // 2
        {{0, -1}, {1, 0}},  // 3
        {{0, 1}, {1, 0}},   // 4
        {{0, -1}, {-1, 0}}, // 5
        {{0, 1}, {-1, 0}}   // 6
    };

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return true;

        vis[i][j] = true;

        for (auto& d : dir[grid[i][j]]) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj])
                continue;

            for (auto& back : dir[grid[ni][nj]]) {
                if (ni + back[0] == i && nj + back[1] == j) {
                    if (dfs(grid, ni, nj))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));

        return dfs(grid, 0, 0);
    }
};
