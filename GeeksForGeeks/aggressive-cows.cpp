class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k, int dist) {
        int n = stalls.size();
        k--;
        int idx = 0;
        int i = 1;
        while(i < n && k > 0) {
            if(stalls[i] - stalls[idx] >= dist) {
                k--;
                idx = i;
            }
            i++;
        }
        return k == 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        auto p = minmax_element(stalls.begin(), stalls.end());
        
        int lo = 1, hi = (*p.second) - (*p.first);
        int ans = 1;
        
        while(lo <= hi) {
            int distance = lo + (hi-lo)/2;
            if(isPossible(stalls, k, distance)) {
                ans = max(ans, distance);
                lo = distance + 1;
            }else {
                hi = distance - 1;
            }
        }
        return ans;
    }
};
