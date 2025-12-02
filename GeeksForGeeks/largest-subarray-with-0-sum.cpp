class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int ans = 0;
        unordered_map<int,int> mp; // store sum and last seen index
        
        mp[0] = -1;
        
        for(int i = 1; i < arr.size(); i++){
            arr[i] += arr[i-1];
        }
        
        int i = 0;
        for(int sum : arr){
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }else {
                mp[sum] = i;
            }
            i++;
        }
        
        return ans;
    }
};