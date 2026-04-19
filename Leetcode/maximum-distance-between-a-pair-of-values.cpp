class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()-1, m = nums2.size()-1;

        int ans = 0;
        int i = n, j = m;
        while(i >= 0 && j >= 0) {
            if(nums1[i] <= nums2[j]) {
                ans = max(ans, j-i);
                i--;
            }else j--;
        }
        return ans;
    }
};
