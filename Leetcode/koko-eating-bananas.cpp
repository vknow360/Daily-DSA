class Solution {
public:
    bool isPossible(vector<int>& piles, int speed, int h) {
        long long hr = 0;
        for (int i : piles) {
            hr += (long long)ceil((i * 1.0) / speed);
        }
        return hr <= (long long)h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(piles, mid, h)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};