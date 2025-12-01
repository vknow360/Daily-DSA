class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int i = n-1, j = n-2, k = n-3;
        
        while(k >= 0){
            if(nums[j]+nums[k] > nums[i]){
                return (nums[j]+nums[k]+nums[i]);
            }else{
                i--;
                j--;
                k--;
            }
        }
        return 0;
    }
};