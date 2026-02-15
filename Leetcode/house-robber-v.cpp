class Solution {
public:
    vector<vector<long long>> dp;
    long long helper(vector<int>& nums, vector<int>& colors, int curr, int prev) {
        if(curr == nums.size()) {
            return 0;
        }

        if(dp[curr][prev] != -1) {
            return dp[curr][prev];
        }
        long long take = 0;
        if(prev == 0 || curr == 0 || colors[curr] != colors[curr-1]) {
            // can rob current house
            take = nums[curr] + helper(nums, colors, curr+1, 1);
        }

        // skip current house
        long long skip = helper(nums, colors, curr+1, 0);

        return dp[curr][prev] = max(take, skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return helper(nums, colors ,0, 0);
    }
};
