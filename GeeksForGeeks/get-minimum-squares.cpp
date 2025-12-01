class Solution {
  public:
    int solve(int n, unordered_map<int,int>& mp){
        if(n == 0) return 0;
        
        if(mp.find(n) == mp.end()) {
            int srt = sqrt(n);
            if(srt*srt == n){
                mp[n] = 1;
            }else {
                int mn = INT_MAX;
                for(int i = 1; i*i <= n; i++){
                    mn = min(mn, solve(n - i*i, mp));
                }
                mp[n] = 1+mn;
            }
        }
        return mp[n];
    }
    
    int solve2(int n){
        int srt = sqrt(n);
        if(srt * srt == n) return 1;
        for(int i = 1; i <= srt; i++){
            int srtRem = sqrt(n-i*i);
            if(srtRem*srtRem == n-i*i) return 2;
        }
        
        int temp = n;
        while(temp % 4 == 0) temp /= 4;
        
        if(temp%8 == 7) return 4;
        
        return 3;
    }
    int minSquares(int n) {
        // Code here
        unordered_map<int, int> mp;
        //return solve(n, mp);
        
        return solve2(n);
    }
};