class Solution {
public:
    int solve(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0); 
        
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= nums.size(); i++) {
            int skip = dp[i-1];
            int steal = nums[i-1] + dp[i-2];
            dp[i] = max(skip, steal);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
