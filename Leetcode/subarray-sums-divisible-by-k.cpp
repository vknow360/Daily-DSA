class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1;

        int pref = 0;

        int count = 0;

        for(int i = 0; i < n; i++) {
            pref += nums[i];
            int rem = (pref % k + k) % k;
            if(mp[rem] > 0) count += mp[rem];

            mp[rem]++;
        }

        return count;
    }
};