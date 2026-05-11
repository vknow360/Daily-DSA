class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int len = 0;

        for(int n : nums) {
            len += (int)log10(n);
            len++;
        }

        vector<int> ans(len);
        int i = len-1, j = nums.size()-1;
        while(i >= 0) {
            int num = nums[j];
            while(num) {
                ans[i--] = num%10;
                num /= 10;
            }
            j--;
        }
        return ans;
    }
};
