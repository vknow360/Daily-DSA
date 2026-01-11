class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                s.insert(nums[j]);
                if(s.count(sum)) ans++;
            }
        }

        return ans;
    }
};
