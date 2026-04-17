class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while(n>0) {
            rev *= 10;
            rev += n%10;
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int i = 0;
        for(int num : nums) {
            int rev = reverse(num);
            if(mp.find(num) != mp.end()) {
                ans = min(ans, i - mp[num]);
            }
            mp[rev] = i++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
