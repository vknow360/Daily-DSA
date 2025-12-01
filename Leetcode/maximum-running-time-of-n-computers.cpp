class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        int len = batteries.size();
        if(len == n) return batteries[0];

        long long sum = 0;
        for(int i : batteries) sum += i;

        long long ans = INT_MIN;

        long long lo = 0, hi = sum/n;

        auto isPossible = [&](long long time) {
            long long usable = 0;
            for(int i : batteries) usable += min(((long long)i), time);

            return n*time <= usable;
        };

        while(lo <= hi) {
            long long mid = lo + (hi-lo)/2;
            if(isPossible(mid)) {
                ans = max(ans, mid);
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }

        return ans;

    }
};