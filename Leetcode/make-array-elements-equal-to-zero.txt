class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0, left = 0, right = 0;
        for(int i : nums) right += i;

        for(int i : nums){
            left += i;
            right -= i;
            if(i != 0) continue;
            if(left == right) count += 2;
            else if(abs(left-right) == 1) count++;
        }
        return count;
    }
};