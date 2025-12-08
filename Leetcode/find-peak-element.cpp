class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        else if(nums[0] > nums[1]) return 0;
        else if(nums[n-1] > nums[n-2]) return n-1;

        auto get = [&](int i) {
            if(i < 0) return -1;
            else if(i >= n) return INT_MIN;
            else return nums[i];
        };

        int lo = 0, hi = n-1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(get(mid) > get(mid-1) && get(mid) > get(mid+1)) return mid;
            else if(get(mid) < get(mid+1)) {
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }
        return hi;
    }
};
