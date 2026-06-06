class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 0);
        for(int i = n-2; i >= 0; i--) {
            suff[i] = suff[i+1] + nums[i+1];
        }
        
        vector<int> ans(n, 0);
        int pref = 0;
        for(int i = 0; i < n; i++) {
            ans[i] = abs(pref - suff[i]);
            pref += nums[i];
        }
        return ans;
    }
};
