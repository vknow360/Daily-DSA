class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0, j = n-1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            ans = max(sum, ans);
            i++;
            j--;
        }

        return ans;
    }
};
