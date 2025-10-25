class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int q = n / 7;
        for (int i = 0; i < q; i++) {
            sum += ((7 + i) * (7 + i + 1)) / 2;
            sum -= (i * (i + 1)) / 2;
        }
        int r = n % 7;
        sum += ((q + r) * (q + r + 1)) / 2;
        sum -= ((q + 1) * q) / 2;
        return sum;
    }
};