class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        int num = 0;
        for(int i : nums) {
            num = ((num << 1) + i) % 5;
            ans.push_back(num == 0);
        }
        return ans; 
    }
};