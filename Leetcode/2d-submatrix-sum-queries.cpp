class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = (i > 0) ? mat[i - 1][j] : 0;
                int left = (j > 0) ? mat[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? mat[i - 1][j - 1] : 0;
                mat[i][j] += up + left - diag;
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            int res = mat[r2][c2];
            if (r1 > 0) res -= mat[r1 - 1][c2];
            if (c1 > 0) res -= mat[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) res += mat[r1 - 1][c1 - 1];

            ans.push_back(res);
        }
        return ans;
    }
};
