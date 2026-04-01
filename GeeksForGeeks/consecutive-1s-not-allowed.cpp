class Solution {
  public:
    int countStrings(int n) {
        // code here
        if(n == 1) return 2;
        else if(n == 2) return 3;
        
        int prevprev = 2;
        int prev = 3;
        for(int i = 3; i <= n; i++) {
            int nxt = prev + prevprev;
            prevprev = prev;
            prev = nxt;
        }
        return prev;
    }
};
