class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int i, int n) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int skip = solve(nums, i + 1, n);
        int steal = nums[i] + solve(nums, i + 2, n);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        dp.assign(nums.size()+1, -1);
        int case1 = solve(nums, 0, nums.size()-1);
        dp.assign(nums.size()+1, -1);
        int case2 = solve(nums,1, nums.size());

        return max(case1, case2);
    }
};
