class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pos;
        for(int i : nums) {
            if(i >= 0) pos.push_back(i);
        }

        if(pos.empty()) return nums;

        int len = pos.size();
        k %= len;

        rotate(pos.begin(), pos.begin() + k, pos.end());

        int i = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] >= 0) {
                nums[j] = pos[i];
                i++;
            }
        }
        return nums;
    }
};
