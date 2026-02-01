class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return nums[0]+nums[1]+nums[2];

        int a = 0;
        int b = min_element(nums.begin()+1, nums.end()) - nums.begin();
        swap(nums[b], nums[1]);
        int c = min_element(nums.begin()+2, nums.end()) - nums.begin();

        return nums[0] + nums[1] + nums[c];
    }
};
