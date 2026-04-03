class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        vector<int> res;
        int row = 0, col = 0;
        while(col < n) {
            int r = row, c = col;
            while(r != n && c != -1) {
                res.push_back(mat[r][c]);
                r++;
                c--;
            }
            col++;
        }
        col--;
        row++;
        while(row < n) {
            int r = row, c = col;
            while(r != n && c >= 0) {
                res.push_back(mat[r][c]);
                r++;
                c--;
            }
            row++;
        }
        return res;
    }
};
