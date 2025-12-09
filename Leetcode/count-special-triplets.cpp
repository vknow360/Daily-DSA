class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;

        int n = nums.size();
        
        unordered_map<int, long long> right;
        for(int i : nums) right[i]++;

        unordered_map<int, long long> left;

        long long count = 0;
        for(int i = 0; i < n; i++) {
            int val = nums[i];
            int dbl = val*2;
            
            right[val]--;

            if(right.count(dbl) && left.count(dbl)) {
                count += left[dbl] * right[dbl];
            }

            left[val]++;
        }

        return count%MOD;
    }
};
