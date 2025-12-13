class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n = mat.size()-1;
        for(int i = 0; i <= n; i++) {
            swap(mat[i][i], mat[i][n-i]);
        }
    }
};
