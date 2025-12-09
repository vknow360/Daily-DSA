class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();
        int bqts = 0;
        int count = 0;
        for(int i : bloomDay) {
            if(i <= day) {
                count++;
                if(count == k) {
                    bqts++;
                    count = 0;
                }
            }else count = 0;
        }
        return bqts >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k > n) return -1;

        auto p = minmax_element(bloomDay.begin(), bloomDay.end());

        int lo = *p.first;
        int hi = *p.second;

        int ans = hi;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid-1;
            }else lo = mid + 1;
        }

        return ans;
    }
};
