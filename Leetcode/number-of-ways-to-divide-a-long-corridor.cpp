class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1000000007;

        int seats = 0;
        for (char c : corridor)
            if (c == 'S') seats++;
        if (seats == 0 || seats % 2 != 0)
            return 0;

        long long ans = 1;
        int sCount = 0;
        int firstSeat = -1;
        int prevEnd = -1;

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                if (sCount == 0) firstSeat = i;
                sCount++;

                if (sCount == 2) {
                    if (prevEnd != -1) {
                        ans = (ans * (firstSeat - prevEnd)) % MOD;
                    }
                    prevEnd = i;
                    sCount = 0;
                }
            }
        }
        return ans;
    }
};
