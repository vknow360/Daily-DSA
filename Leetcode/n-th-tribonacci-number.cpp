class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n <= 2) return 1;

        int z = 0;
        int o = 1;
        int t = 1;

        for(int i = 3; i <= n; i++) {
            int curr = z + o + t;
            z = o;
            o = t;
            t = curr;
        }

        return t;
    }
};
