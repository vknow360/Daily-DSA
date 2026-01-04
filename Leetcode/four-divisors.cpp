class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        if (n % 2 == 0)
            return n == 2;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        // condition for exactly four divisors
        // 1) num = p*p*p , where p is a prime number
        // or, 2) num = p*q, where both p and q are prime
        int ans = 0;
        for (int num : nums) {

            // Case 1: p^3
            int p = round(cbrt(num));
            if (1LL * p * p * p == num && isPrime(p)) {
                ans += 1 + p + p * p + num;
                continue;
            }

            // Case 2: p * q
            int d = -1;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    d = i;
                    break;
                }
            }

            if (d == -1)
                continue;

            int a = d;
            int b = num / d;

            if (a != b && isPrime(a) && isPrime(b)) {
                ans += 1 + a + b + num;
            }
        }
        return ans;
    }
};
