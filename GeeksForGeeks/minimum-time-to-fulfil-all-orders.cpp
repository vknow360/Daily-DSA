class Solution {
  public:
    bool isPossible(vector<int>& ranks, int n, int time) {
        int dnts = 0;
        for(int r : ranks) {
            // let donuts made by chef of rank r be x
            int x = (-1 + sqrt(1+((8*time)/r)))/2;
            dnts += x;
        }
        return dnts >= n;
    }
    int minTime(vector<int>& ranks, int n) {
        // code here
        sort(ranks.begin(), ranks.end());
        int ans = INT_MAX;
        int lo = 0;
        int hi = ranks.back() * (n*(n+1))/2; // time = r * (1 + 2 + 3 + ... + n)
        while(lo <= hi) {
            int time = lo + (hi-lo)/2;
            if(isPossible(ranks, n, time)) {
                ans = time;
                hi = time-1;
            }else lo = time+1;
        }
        return ans;
    }
};
