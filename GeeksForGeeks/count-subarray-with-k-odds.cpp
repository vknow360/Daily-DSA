class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> pref;
        int odd = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i]%2 != 0) {
                odd++;
            }
            pref.push_back(odd);
        }
        
        int ans = 0;
        
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            int pR = pref[i];
            ans += mp[pR-k];
            if(mp.find(pR) == mp.end()) mp[pR] = 1;
            else mp[pR]++;
        }
        
        return ans;
    }
};
