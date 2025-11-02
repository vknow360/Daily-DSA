class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'a'));
        for (auto& v : walls)
            grid[v[0]][v[1]] = 'W';
        for (auto& v : guards)
            grid[v[0]][v[1]] = 'R';

        for (auto& v : guards) {
            int r = v[0], c = v[1];

            for (int j = c + 1; j < n; ++j) {
                if (grid[r][j] == 'W' || grid[r][j] == 'R')
                    break;
                grid[r][j] = 'G';
            }
            for (int j = c - 1; j >= 0; --j) {
                if (grid[r][j] == 'W' || grid[r][j] == 'R')
                    break;
                grid[r][j] = 'G';
            }
            for (int i = r + 1; i < m; ++i) {
                if (grid[i][c] == 'W' || grid[i][c] == 'R')
                    break;
                grid[i][c] = 'G';
            }
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c] == 'W' || grid[i][c] == 'R')
                    break;
                grid[i][c] = 'G';
            }
        }

        int unguarded = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 'a')
                    ++unguarded;

        return unguarded;
    }
};
