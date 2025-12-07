class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long sum = 0;
        for(int i : nums) sum += i;
        if(sum % p == 0) return 0;

        int ans = INT_MAX;
        int target = sum%p;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long pref = 0;

        for(int i = 0; i < n; i++) {
            pref += nums[i];
            int req = (pref - target + p) % p;
            if(mp.find(req) != mp.end()) {
                ans = min(ans, i - mp[req]);
            }
            mp[pref%p] = i;
        }

        if(ans == n) return -1;

        return ans;
    }
};