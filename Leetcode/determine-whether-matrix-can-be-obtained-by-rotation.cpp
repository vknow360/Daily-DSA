class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        auto equals = [&]() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) return false;
                }
            }
            return true;
        };

        if(equals()) return true;

        auto rotate = [&]() {
            for(int i = 0; i < n; i++) {
                int col = n-i-1;
                for(int j = i+1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for(int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
        };

        for(int i = 0; i < 3; i++){
            rotate();
            if(equals()) return true;
        }
        return false;
    }
};
