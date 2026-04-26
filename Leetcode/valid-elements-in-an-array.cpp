class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> suf(n, 0);
        suf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf[i] = max(nums[i+1], suf[i+1]);
        }
        int mx = 0;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > mx || nums[i] > suf[i]) ans.push_back(nums[i]);
            mx = max(nums[i], mx);
        }
        ans.push_back(nums.back());
        return ans;
    }
};
