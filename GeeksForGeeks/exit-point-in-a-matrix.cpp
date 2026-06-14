class Solution {
  public:
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    bool isSafe(int n, int m, int i, int j) {
        return !(i < 0 || j < 0 || i >= n || j >= m);
    }
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = 0, dir = 0;
        while(true) {
            dir = (dir + mat[i][j])%4;
            auto [dx, dy] = dirs[dir];
            if(isSafe(n, m, i+dx, j+dy)) {
                if(mat[i][j]) mat[i][j] = 0;
                i += dx;
                j += dy;
            }else return {i, j};
        }
    }
};
