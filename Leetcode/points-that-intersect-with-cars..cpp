class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> freq(102, 0);
        for (auto &r : nums) {
            freq[r[0]]++;
            freq[r[1] + 1]--;
        }

        int cnt = 0;
        int active = 0;
        for (int i = 1; i <= 100; i++) {
            active += freq[i];
            if (active > 0) cnt++;
        }
        return cnt;
    }
};