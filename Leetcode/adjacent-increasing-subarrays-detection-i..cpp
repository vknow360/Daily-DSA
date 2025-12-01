class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        bool poss = false;
        int i = 0, j = i+k;
        while(j <= n-k){
            int count = 0;
            for(int li = 0; li < k-1; li++){
                if(
                    (nums[i+li+1] > nums[i+li]) &&
                    (nums[j+li+1] > nums[j+li])
                ) count++;
                else break;
            }
            if(count == k-1){
                poss = true;
                break;
            }else{
                i++;
                j++;
            }
        }
        return poss;
    }
};