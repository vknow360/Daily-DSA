class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            while(nums[j] > 2* nums[i]) i++;
            for(int k = i; k < j; k++) {
                ans = max(ans, nums[k] xor nums[j]);
            }
        }
        return ans;
    }
};
