class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int levels = min(m, n) / 2;

        for (int level = 0; level < levels; level++) {
            int rowSt = level, rowEnd = m - level;
            int colSt = level, colEnd = n - level;
            vector<int> v;

            // top row
            for (int j = colSt; j < colEnd; j++)
                v.push_back(grid[rowSt][j]);

            // right column
            for (int i = rowSt + 1; i < rowEnd; i++)
                v.push_back(grid[i][colEnd - 1]);

            // bottom row
            for (int j = colEnd - 2; j >= colSt; j--)
                v.push_back(grid[rowEnd - 1][j]);

            // left column
            for (int i = rowEnd - 2; i > rowSt; i--)
                v.push_back(grid[i][colSt]);

            int len = v.size();
            int shift = k % len;

            reverse(v.begin(), v.begin() + shift);
            reverse(v.begin() + shift, v.end());
            reverse(v.begin(), v.end());

            int l = 0;
            // top row
            for (int j = colSt; j < colEnd; j++)
                grid[rowSt][j] = v[l++];

            // right column
            for (int i = rowSt + 1; i < rowEnd; i++)
                grid[i][colEnd - 1] = v[l++];

            // bottom row
            for (int j = colEnd - 2; j >= colSt; j--)
                grid[rowEnd - 1][j] = v[l++];

            // left column
            for (int i = rowEnd - 2; i > rowSt; i--)
                grid[i][colSt] = v[l++];
        }
        return grid;
    }
};
