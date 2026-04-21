class Solution {
  public:
    int solve(int fromCap, int toCap, int d) {
        int from = 0, to = 0, steps = 0;
        while(from != d && to != d) {
            if(from == 0) {
                from = fromCap;
                steps++;
            }else if(to == toCap) {
                to = 0;
                steps++;
            }else {
                int transfer = min(from, toCap - to);
                from -= transfer;
                to += transfer;
                steps++;
            }
        }
        return steps;
    }
    int minSteps(int m, int n, int d) {
        if(d % gcd(m, n) != 0) return -1;
        if(d > max(m, n)) return -1;
        
        return min(
            solve(m, n, d),
            solve(n, m, d)
        );
    }
};
