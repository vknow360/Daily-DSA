class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int q) {
        int res = 0;
        for(int i : nums) {
            res += (i+q-1)/q;
            if(res > threshold) return false;
        }
        return res <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
                
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int ans = 1;
        while(lo <= hi) {
            int q = lo + (hi-lo)/2;
            if(isPossible(nums, threshold, q)) {
                ans = q;
                hi = q-1;
            }else {
                lo = q+1;
            }

        }
        return ans;
    }
};
