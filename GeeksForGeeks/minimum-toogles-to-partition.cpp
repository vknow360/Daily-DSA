class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> pref(n, 0);
        pref[0] = arr[0] == 0 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1] + (arr[i] == 0 ? 1 : 0);
        }
        
        int ans = n;
        for(int i = 0; i < n; i++) {
            int left = i - pref[i];
            int right = pref[n-1] - pref[i-1];
            ans = min(ans, left+right);
        }
        return ans;
    }
};
