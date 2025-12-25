class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        int st = 0;
        while(st < k && st < n) {
            ans += max(0, happiness[st] - st);
            st++;
        }
        return ans;
    }
};
