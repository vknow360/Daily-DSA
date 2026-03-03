class Solution {
  public:
    int countDer(int n) {
        
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        int p = 1;
        int pp = 0;
        
        for(int i = 3; i <= n; i++) {
            int tmp = p;
            p = (i-1) * ( p + pp );
            pp = tmp;
        }
        
        return p;
    }
};
