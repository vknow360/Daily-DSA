class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long absSum = 0;
        long long cntNeg = 0;
        long long smllNeg = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int val = matrix[i][j];
                absSum += abs(val);
                if(val < 0) {
                    cntNeg++;
                }
                if(abs(val) < smllNeg) smllNeg = abs(val);
            }
        }

        if(cntNeg % 2 == 0) return absSum;
        else {
            return absSum - 2*smllNeg;
        }
    }
};
