class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int sum) {
        int n = nums.size();
        int sb = 1;
        int currSum = 0;
        for(int i : nums) {
            if(i > sum) return false;
            if(currSum + i <= sum) currSum += i;
            else {
                sb++;
                currSum = i;
            }
        }
        return sb <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());

        int sum = 0;
        for(int i : nums) sum += i;

        int lo = *max_element(nums.begin(), nums.end()), hi = sum;
        int ans = hi;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(isPossible(nums, k, mid)) {
                ans = mid;
                hi = mid-1;
            }else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
