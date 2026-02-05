class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        auto getIdx = [&](auto idx) {
            return ((idx%n)+n)%n;
        };

        vector<int> res;

        for (int i = 0; i< n; i++) {
            int val = nums[i];
            res.push_back(nums[getIdx(i+val)]);
        }

        return res;
    }
};
