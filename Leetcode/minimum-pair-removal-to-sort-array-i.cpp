class Solution {
public:
    bool isSorted(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        int idx = 0;
        while(!isSorted(nums)) {
            long long sum = nums[0]+nums[1];
            int ni = 0;
            for(int i = 1; i < nums.size()-1; i++) {
                long long lsum = nums[i] + nums[i+1];
                if(lsum < sum) {
                    ni = i;
                    sum = lsum;
                }
            }
            auto it = nums.begin()+ni+1;
            nums.erase(it);
            nums[ni] = sum;
            ans++;
        }

        return ans;
    }
};
