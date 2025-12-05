class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }

        int result = 0;

        for(int i = 0; i < n-1; i++) {
            int diff = nums.back() - 2*nums[i];
            if(diff%2 == 0) result++;
        }

        return result;
    }
};
