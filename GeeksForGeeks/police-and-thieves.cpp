class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int ans = 0;
        
        vector<int> police, thief;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 'P') police.push_back(i);
            else thief.push_back(i);
        }
        
        int p = 0, t = 0;
        while(p < police.size() && t < thief.size()) {
            if(abs(thief[t]-police[p]) <= k) {
                p++;
                t++;
                ans++;
            }else {
                if(thief[t]-police[p] > k) {
                    p++;
                }else t++;
            }
            
            if(p == police.size()) break;
            if(t == thief.size()) break;
        }
        return ans;
    }
};
