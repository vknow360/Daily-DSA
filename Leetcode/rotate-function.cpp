class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int prev = 0;
        for(int i = 0; i < n; i++) {
            prev += i*nums[i];
        }
        int ans = prev;
        for(int k = 1; k < n; k++) {
            prev += sum - n*nums[n-k];
            ans = max(ans, prev);
        }

        return ans;
    }
};
