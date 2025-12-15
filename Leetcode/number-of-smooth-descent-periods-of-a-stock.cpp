class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int count = 1;
        long long ans = n;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1)
                count++;
            else {
                if (count > 1) {
                    ans += (1LL * count * (count - 1)) / 2;
                }
                count = 1;
            }
        }
        if (count > 1) {
            ans += (1LL * count * (count - 1)) / 2;
        }
        return ans;
    }
};
