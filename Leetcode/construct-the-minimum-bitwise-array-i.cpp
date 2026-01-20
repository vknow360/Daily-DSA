class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int z : nums) {
            if (z <= 2 || (z & (z - 1)) == 0) {
                ans.push_back(-1);
                continue;
            }

            for(int i = 1; i < z; i++) {
                if((i|(i+1)) == z) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
