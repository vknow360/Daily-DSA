class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
        for(int row = 1; row <= rowIndex; row++) {
            vector<int> curr(row+1, 1);
            for(int col = 1; col < row; col++) {
                curr[col] = dp[col-1] + dp[col];
            }
            dp = curr;
        }
        return dp;
    }
};
