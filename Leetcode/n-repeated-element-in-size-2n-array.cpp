class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums[0] == nums[1] || nums[0] == nums[2]) return nums[0];
        else if(nums[1] == nums[2]) return nums[1];
        
        int candidate = -1;
        int votes = 0;
        for (int i = 3; i < nums.size(); i++) {
            int c = nums[i];
            if (votes == 0) {
                candidate = c;
                votes = 1;
            } else {
                if(c == candidate) votes++;
                else votes--;
            }
        }
        return candidate;
    }
};
