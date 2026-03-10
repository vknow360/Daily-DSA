class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int mxSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > mxSum || (target + mxSum) %2 != 0) return 0;

        int req = (target + mxSum) / 2;

        vector<vector<int>> dp;
        dp.assign(n+1, vector<int>(req+1, 0)); 

        dp[0][0] = 1;

        for(int idx = 1; idx <= n; idx++) {
            int num = nums[idx-1];
            for(int sum = 0; sum <= req; sum++) {
                if(num <= sum) {
                    dp[idx][sum] = dp[idx-1][sum] + dp[idx-1][sum - num];
                }else {
                    dp[idx][sum] = dp[idx-1][sum];
                }
            }
        }

        return dp[n][req];
    }
};
