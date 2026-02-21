class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {
            2,
            3,
            5,
            7,
            11,
            13,
            17,
            19
        };

        int ans = 0;
        for(int n = left; n <= right; n++){
            int cnt = countSetBits(n);
            if(primes.count(cnt)) ans++;
        }

        return ans;
    }
};
