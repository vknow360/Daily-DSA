class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        if(k%n == 0) return true;
        k %= n;
        vector<vector<int>> cp = mat;
        for(int i = 0; i < m; i++) {
            auto bg = mat[i].begin();
            auto end = mat[i].end();
            if(i%2 == 0) {
                reverse(bg, bg+k);
                reverse(bg+k, end);
                reverse(bg, end);
            }else {
                reverse(bg, end);
                reverse(bg, bg+k);
                reverse(bg+k, end);
            }
        }

        return cp == mat;
    }
};
