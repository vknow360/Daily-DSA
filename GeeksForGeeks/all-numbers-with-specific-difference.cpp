class Solution {
  public:
    int sum(int num) {
        int sm = 0;
        while(num > 0) {
            sm += num%10;
            num /= 10;
        }
        return sm;
    }
    bool isPossible(int d, int k) {
        int sm = sum(k);
        return (k-sm) >= d;
    }
    int getCount(int n, int d) {
        // code here
        int ans = 0;
        int lo = 1, hi = n;
        while(lo <= hi) {
            int num = lo + (hi-lo)/2;
            if(isPossible(d, num)) {
                ans = num;
                hi = num-1;
            }else lo = num+1;
        }
        if(ans == 0) return 0;
        return (n-ans+1);
    }
};
