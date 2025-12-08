class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;

        int ans = 0;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int other = -1;
            if(mid <= n-2 && nums[mid+1] == nums[mid]) {
                other = mid+1;
            }

            if(mid > 0 && nums[mid-1] == nums[mid]) {
                other = mid-1;
            }

            if(other == -1) {
                ans = nums[mid];
                break;
            }

            if(min(mid, other)%2 != 0) hi = mid-1;
            else lo = mid+1;
        }
        return ans;
    }
};
