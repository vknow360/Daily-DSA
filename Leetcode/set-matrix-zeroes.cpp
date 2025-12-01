class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        unordered_set<int> lr, lc;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) {
                    lr.insert(i);
                    lc.insert(j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(lr.count(i) || lc.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};