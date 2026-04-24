class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        int mx = 0;
        
        for(int h : arr) {
            if(h >= mx) {
                ans++;
                mx = h;
            }
        }
        return ans;
    }
};
