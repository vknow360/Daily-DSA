class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n), mn(n);
        mx[0] = nums[0];
        mn[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            mx[i] = max(mx[i-1], nums[i]);
        }

        for(int i = n-2; i >= 0; i--) {
            mn[i] = min(nums[i], mn[i+1]);
        }

        vector<int> ans(n);
        ans[n-1] = mx[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(mx[i] > mn[i+1]) {
                ans[i] = ans[i+1];
            }else ans[i] = mx[i];
        }
        return ans;
    }
};
