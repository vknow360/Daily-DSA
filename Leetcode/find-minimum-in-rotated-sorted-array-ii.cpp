class Solution {
public:
    int BS(vector<int>& nums, int lo, int hi) {
        if(lo == hi) return nums[lo];

        if(nums[lo] < nums[hi]) return nums[lo];

        int mid = lo + (hi - lo)/2;

        return min(
            BS(nums, lo, mid),
            BS(nums, mid+1, hi)
        );
    }
    int findMin(vector<int>& nums) {
        return BS(nums, 0, nums.size()-1);
    }
};
