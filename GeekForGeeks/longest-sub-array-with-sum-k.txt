class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }
        
        unordered_map<int, int> mp;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == k) ans = max(ans, i+1);
            else {
                int comp = (arr[i] - k);
                if(mp.find(comp) != mp.end()){
                    ans = max(ans, i - mp[comp]);
                }
                if(mp.find(arr[i]) == mp.end()) {
                    mp[arr[i]] = i;
                }
            }
        }
        return ans;
    }
};