class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j<n && nums[j] <= 1LL*nums[i]*k) j++;
            ans = max(ans, j-i);
        }
        return n-ans;
    }
};
