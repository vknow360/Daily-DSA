class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        int left = 0, right = m-1;
        while(right < n) {
            ans = min(ans, a[right]-a[left]);
            left++;
            right++;
        }
        
        return ans;
    }
};
