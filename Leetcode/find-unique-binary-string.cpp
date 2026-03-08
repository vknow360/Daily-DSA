class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        while(ans.size() < n) ans.push_back('0');
        for(int i = 0; i < n; i++) {
            ans[i] = (1 - (nums[i][i] - '0')) + '0';
        }
        return ans;
    }
};
