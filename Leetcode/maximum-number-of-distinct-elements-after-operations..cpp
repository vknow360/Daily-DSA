class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int prev = INT_MIN;
        int count = 0;
        for(int i : nums){
            int l = i-k;
            int r = i+k;
            int tmp = max(prev+1, l);
            if(r < tmp) continue;
            prev = tmp;
            count++;
        }
        return count;
    }
};