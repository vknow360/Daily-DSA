class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int n = high-low+1;
        vector<int> pres(n, false);
        for(int e : arr) {
            if(e < low || e > high) continue;
            pres[e-low] = true;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!pres[i]) ans.push_back(low+i);
        }
        
        return ans;
    }
};
